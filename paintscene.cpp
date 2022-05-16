#include "paintscene.h"
#include "shapeslistserializer.h"
#include "json.hpp"
#include "shape.h"

#include <QDebug>
#include <algorithm>
#include <QList>
#include <iostream>
#include <fstream>

PaintScene::PaintScene(GlobParams *globParams, ShapesCreator* shapesCreator) :
    globParams(globParams), shapesCreator(shapesCreator)
{

}

PaintScene::PaintScene(qreal x, qreal y, qreal width, qreal height, GlobParams *globParams) :
    QGraphicsScene(x, y, width, height), globParams(globParams)
{

}

void PaintScene::setShapeToDraw(const QString shapeName)
{
    shapeToDraw = shapeName;
    if(tmpShape != nullptr)
    {
        tmpShape->setIsCompleted(true);
        tmpShape = nullptr;
    }
}

void PaintScene::undo()
{
    qDebug() << "Undo.\n";
    if(!undoList.empty())
    {
        Shape* item = undoList.back();
        undoList.pop_back();
        if(items().contains(item))
        {
            removeItem(item);
            //allShapes.erase(std::find(allShapes.begin(), allShapes.end(), item));
        }
        else
        {
            addItem(item);
            //allShapes.push_back(item);
        }
        redoList.push_back(item);
    }
    update(0, 0, width(), height());
}

void PaintScene::redo()
{
    qDebug() << "Redo.\n";
    if(!redoList.empty())
    {
        Shape* item = redoList.back();
        redoList.pop_back();
        if(items().contains(item))
        {
            removeItem(item);
            //allShapes.erase(std::find(allShapes.begin(), allShapes.end(), item));
        }
        else
        {
            addItem(item);
            //allShapes.push_back(item);
        }
        undoList.push_back(item);
    }
    update(0, 0, width(), height());
}

void PaintScene::serializeDrawnShapesList()
{
    qDebug() << "Serialize drawn shape list.\n";
    QList<Shape*> shapesList;
    QList<QGraphicsItem*> graphicsItems = items();
    for(auto item : graphicsItems)
    {
        Shape* tmp = dynamic_cast<Shape*>(item);
        if (tmp != nullptr && tmp->getIsCompleted())
            shapesList.append(tmp);
    }

    dumpShapesListToFile(shapesList, "json_shapes.json");
}

void PaintScene::deserializeDrawnShapesList()
{
    qDebug() << "Deserialize drawn shapes list.\n";
    clear();
    tmpShape = nullptr;
    QString fileName = "json_shapes.json";
    using json = nlohmann::json;
    std::ifstream in(fileName.toStdString());
    json shapesArray = json::parse(readAllText(in));
    in.close();

    if (shapesArray.is_null())
    {
        return;
    }

    for (int i = 0; i < shapesArray.size(); i++)
    {
        json currShapeJson = shapesArray[i];

        Shape *s = shapesCreator->createShape(currShapeJson["name"]);
        addItem(s);
        std::cout << currShapeJson["name"] << "\n";
        std::vector<QPointF> shapePoints;

        for (int j = 0; j < currShapeJson["points"].size(); j++)
        {
            json currPointJson = currShapeJson["points"][j];
            shapePoints.push_back(QPointF(currPointJson[0], currPointJson[1]));
        }
        s->setPoints(shapePoints);
        json startPoint = currShapeJson["startPoint"];
        s->setStartPoint(QPointF(startPoint[0], startPoint[1]));
        json endPoint = currShapeJson["endPoint"];
        s->setEndPoint(QPointF(endPoint[0], endPoint[1]));

        s->setPoints(shapePoints);
        s->setPenWidth(currShapeJson["penWidth"]);

        json colorJson = currShapeJson["penColor"];
        s->setPenColor(QColor(colorJson[0], colorJson[1], colorJson[2]));
        colorJson = currShapeJson["brushColor"];
        s->setBrushColor(QColor(colorJson[0], colorJson[1], colorJson[2]));
    }
    undoList.clear();
    redoList.clear();
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    qDebug() << "Mouse press event.\n";
    if(globParams->isDrawAction())
    {
        qDebug() << "Mouse press event event->pos(): " << event->pos();
        //tmpShape = shapeToDraw->clone();
        //tmpShape->setPos(event->pos());
        if(tmpShape == nullptr || tmpShape->getIsCompleted())
        {
            tmpShape = shapesCreator->createShape(shapeToDraw.toStdString());
            tmpShape->setPenColor(globParams->getCurrentPenColor());
            tmpShape->setBrushColor(globParams->getCurrentBrushColor());
            tmpShape->setPenWidth(globParams->getCurrentPenWidth());
            addItem(tmpShape);
            undoList.push_back(tmpShape);
            tmpShape->setStartPoint(event->scenePos());
        }

        tmpShape ->setEndPoint(event->scenePos());
        tmpShape->addPoint(event->scenePos());
        update(0, 0, width(), height());
        qDebug() << tmpShape->getName() << '\n';
    }

}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Mouse move event.\n";
    qDebug() << "Mouse move event->pos(): " << event->scenePos().x();

    if(globParams->isDrawAction())
    {
        tmpShape->setEndPoint(event->scenePos());
        update(0, 0, width(), height());
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Mouse release event.\n";
    if(globParams->isDrawAction())
    {
        tmpShape->setEndPoint(event->scenePos());
        tmpShape->addPoint(event->scenePos());
        if(!tmpShape->isDrawnInTwoClicks())
        {
            //allShapes.push_back(tmpShape);
        }
        else
        {
            tmpShape->setIsCompleted(true);
        }
        update(0, 0, width(), height());
        redoList.clear();
    }
}

void PaintScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug() << "Mouse double click event.\n";
    if(globParams->isDrawAction())
    {
        if(!tmpShape->isDrawnInTwoClicks())
        {
            //allShapes.push_back(tmpShape);
            tmpShape->setIsCompleted(true);
        }
    }
}

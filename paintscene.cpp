#include "paintscene.h"

#include <QDebug>

PaintScene::PaintScene(GlobParams *globParams, ShapesCreator* shapesCreator) :
    globParams(globParams), shapesCreator(shapesCreator)
{

}

PaintScene::PaintScene(qreal x, qreal y, qreal width, qreal height, GlobParams *globParams) :
    QGraphicsScene(x, y, width, height), globParams(globParams)
{

}

void PaintScene::undo()
{
    qDebug() << "Undo.\n";
    if(!undoList.empty())
    {
        Shape* item = undoList.back();
        undoList.pop_back();
        if(items().contains(item))
            removeItem(item);
        else
            addItem(item);
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
            removeItem(item);
        else
            addItem(item);
        undoList.push_back(item);
    }
    update(0, 0, width(), height());
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
            allShapes.push_back(tmpShape);
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
            allShapes.push_back(tmpShape);
            tmpShape->setIsCompleted(true);
        }
    }
}

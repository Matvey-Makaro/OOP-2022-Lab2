#include "shapeslistserializer.h"
#include "json.hpp"
#include "shape.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using json = nlohmann::json;

void dumpShapesListToFile(QList<Shape *> shapesList, const QString& fileName)
{
    std::cout << "dump the list of shapes to " << fileName.toStdString() << "\n";
    json shapesArray = {};

    for (int i = 0; i < shapesList.size(); i++)
    {
        Shape *currentShape = shapesList[i];
        shapesArray[i]["name"] = currentShape->getName().toStdString();
        shapesArray[i]["penWidth"] = currentShape->getPenWidth();

        QColor penColor = currentShape->getPenColor();
        shapesArray[i]["penColor"] = {penColor.red(), penColor.green(), penColor.blue()};

        QColor brushColor = currentShape->getBrushColor();
        shapesArray[i]["brushColor"] = {brushColor.red(), brushColor.green(), brushColor.blue()};

        shapesArray[i]["startPoint"] = {currentShape->getStartPoint().x(), currentShape->getStartPoint().y()};
        shapesArray[i]["endPoint"] = {currentShape->getEndPoint().x(), currentShape->getEndPoint().y()};

        std::vector<QPointF>& points = currentShape->getPoints();
        shapesArray[i]["points"] = {};

        for (int j = 0; j < points.size(); j++)
        {
            QPointF currPoint = points[j];
            shapesArray[i]["points"][j] = {currPoint.x(), currPoint.y()};
        }
    }

    std::string dumped = shapesArray.dump(2);
    std::ofstream out(fileName.toStdString());
    out << dumped;
    out.close();
}

std::string readAllText(std::ifstream& in) {
    std::ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

QList<Shape *> loadShapesListFromFile(QString fileName, ShapesCreator *creator)
{
    std::cout << "load the list of shapes from " << fileName.toStdString() << "\n";

    std::ifstream in(fileName.toStdString());
    json shapesArray = json::parse(readAllText(in));

    if (shapesArray.is_null())
    {
        return QList<Shape *>();
    }

    QList<Shape *> retList;

    for (int i = 0; i < shapesArray.size(); i++)
    {
        json currShapeJson = shapesArray[i];

        Shape *s = creator->createShape(currShapeJson["name"]);
        std::cout << currShapeJson["name"] << "\n";
        std::vector<QPointF> shapePoints;

        for (int j = 0; j < currShapeJson["points"].size(); j++)
        {
            json currPointJson = currShapeJson["points"][j];
            shapePoints.push_back(QPointF(currPointJson[0], currPointJson[1]));
        }
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

        retList.append(s);
    }

    return retList;
}

#pragma once

#include "shape.h"
#include "shapescreator.h"

#include <QList>
#include <fstream>

void dumpShapesListToFile(QList<Shape *> shapesList, const QString& fileName);
std::string readAllText(std::ifstream& in);
QList<Shape *> loadShapesListFromFile(QString fileName, ShapesCreator *creator);

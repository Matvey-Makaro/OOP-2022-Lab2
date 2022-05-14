#include "shape.h"

#include <QDebug>

Shape::Shape(GlobParams *globParams, QPointF globalStartPoint, QObject *parent):
    globParams(globParams), globalStartPoint(globalStartPoint), QObject(parent)
{
    // Использовать point
    startPoint = endPoint = mapFromScene(globalStartPoint);
    penColor = globParams->getCurrentPenColor();
    penWidth = globParams->getCurrentPenWidth();
    brushColor = globParams->getCurrentBrushColor();
}

QPointF Shape::getStartPoint() const
{
    return startPoint;
}

void Shape::setStartPoint(const QPointF& value)
{
    //startPoint = mapFromScene(value);
    startPoint = value;
    qDebug() << "setStartPoint value: " << startPoint << "\n";
    updateShape();
}

QPointF Shape::getEndPoint() const
{
    return endPoint;
}

void Shape::setEndPoint(const QPointF& value)
{
    //endPoint = mapFromScene(value);
    endPoint = value;
    qDebug() << "setEndPoint value: " << endPoint << '\n';
    updateShape();
}

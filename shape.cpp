#include "shape.h"

#include <QDebug>

Shape::Shape()
{
   setFlags(QGraphicsItem::ItemIsMovable);
}

QRectF Shape::boundingRect() const { return getBoundingRect(); }

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

void Shape::updateShape()
{
    update(getBoundingRect());
}

bool Shape::getIsCompleted() const
{
    return isCompleted;
}

void Shape::setIsCompleted(bool value)
{
    isCompleted = value;
}

int Shape::getPenWidth() const
{
    return penWidth;
}

void Shape::setPenWidth(int value)
{
    penWidth = value;
}

std::vector<QPointF>& Shape::getPoints()
{
    return points;
}

void Shape::setPoints(const std::vector<QPointF> &value)
{
    points = value;
}

void Shape::addPoint(QPointF point)
{
    points.push_back(point);
}

QColor Shape::getBrushColor() const
{
    return brushColor;
}

void Shape::setBrushColor(const QColor &value)
{
    brushColor = value;
}

QColor Shape::getPenColor() const
{
    return penColor;
}

void Shape::setPenColor(const QColor &value)
{
    penColor = value;
}

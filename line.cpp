#include "line.h"

#include <QPen>
#include <qmath.h>
#include <memory>


Line::Line(GlobParams* globParams, QPointF globalStartPoint, QWidget* parent) :
    Shape(globParams, globalStartPoint, parent)
{

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penColor, penWidth));
    painter->drawLine(startPoint, endPoint);

}

QRectF Line::boundingRect() const { return getBoundingRect(); }

std::shared_ptr<Shape> Line::clone(QPointF point) const
{
    return std::make_shared<Line>(globParams, point);
}

void Line::updateShape()
{
    update(getBoundingRect());
}

QRectF Line::getBoundingRect() const
{
    //qreal length = sqrt((startPoint.x() - endPoint.x()) * (startPoint.x() - endPoint.x()) + (startPoint.y() - endPoint.y()) * (startPoint.y() - endPoint.y()));
    return QRectF((startPoint.x() > endPoint.x() ? endPoint.x() : startPoint.x()) - penWidth / 2,
                  (startPoint.y() > endPoint.y() ? endPoint.y() : startPoint.y()) - penWidth / 2,
                  qAbs(endPoint.x() - startPoint.x()) + penWidth / 2,
                  qAbs(endPoint.y() - startPoint.y()) + penWidth / 2);
}

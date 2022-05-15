#include "rectangle.h"

Rectangle::Rectangle(GlobParams *globParams, QPointF globalStartPoint, QWidget *parent) :
    Shape(globParams, globalStartPoint, parent)
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penColor, penWidth));
    painter->setBrush(QBrush(brushColor));
    painter->drawRect(endPoint.x() > startPoint.x() ? startPoint.x() : endPoint.x(),
                      endPoint.y() > startPoint.y() ? startPoint.y() : endPoint.y(),
                      qAbs(startPoint.x() - endPoint.x()),
                      qAbs(startPoint.y() - endPoint.y()));
}

std::shared_ptr<Shape> Rectangle::clone(QPointF point) const
{
    return std::make_shared<Rectangle>(globParams, point);
}

QRectF Rectangle::getBoundingRect() const
{
    return QRectF((endPoint.x() > startPoint.x() ? startPoint.x() : endPoint.x()) - penWidth / 2,
                  (endPoint.x() > startPoint.x() ? startPoint.x() : endPoint.x()) - penWidth / 2,
                  qAbs(startPoint.x() - endPoint.x()) + penWidth / 2,
                  qAbs(startPoint.y() - endPoint.y()) + penWidth / 2);
}

#include "line.h"

#include <QPen>
#include <memory>


Line::Line()
{ }

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penColor, penWidth));
    painter->drawLine(startPoint, endPoint);

}

std::shared_ptr<Shape> Line::clone() const
{
    return std::make_shared<Line>();
}

QRectF Line::getBoundingRect() const
{
    //qreal length = sqrt((startPoint.x() - endPoint.x()) * (startPoint.x() - endPoint.x()) + (startPoint.y() - endPoint.y()) * (startPoint.y() - endPoint.y()));
    return QRectF((startPoint.x() > endPoint.x() ? endPoint.x() : startPoint.x()) - penWidth / 2,
                  (startPoint.y() > endPoint.y() ? endPoint.y() : startPoint.y()) - penWidth / 2,
                  qAbs(endPoint.x() - startPoint.x()) + penWidth / 2,
                  qAbs(endPoint.y() - startPoint.y()) + penWidth / 2);
}

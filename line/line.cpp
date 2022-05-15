#include "line.h"

#include <memory>

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penColor, penWidth));
    painter->drawLine(startPoint, endPoint);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

std::shared_ptr<Shape> Line::clone() const
{
    return std::make_shared<Line>();
}

QRectF Line::getBoundingRect() const
{
    return QRectF((startPoint.x() > endPoint.x() ? endPoint.x() : startPoint.x()) - penWidth / 2,
                  (startPoint.y() > endPoint.y() ? endPoint.y() : startPoint.y()) - penWidth / 2,
                  qAbs(endPoint.x() - startPoint.x()) + penWidth / 2,
                  qAbs(endPoint.y() - startPoint.y()) + penWidth / 2);
}

extern "C" Shape* createShape()
{
    return new Line();
}

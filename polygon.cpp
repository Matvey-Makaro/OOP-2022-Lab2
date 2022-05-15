#include "polygon.h"

#include <QGraphicsScene>

Polygon::Polygon()
{

}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penColor, penWidth));
    painter->setBrush(QBrush(brushColor));
    points.push_back(endPoint);
    painter->drawPolygon(points.data(), points.size());
    points.pop_back();
}

QRectF Polygon::getBoundingRect() const
{
    return scene()->sceneRect();
}

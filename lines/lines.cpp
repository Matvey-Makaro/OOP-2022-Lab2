#include "lines.h"

#include<QVector>
#include<QGraphicsScene>

Lines::Lines()
{
}

void Lines::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penColor, penWidth));
    painter->setBrush(QBrush(brushColor));
    QVector<QLineF> lines;
    lines.push_back(QLineF(startPoint, startPoint));
    for(size_t i = 0; i < points.size() - 1; i++)
    {
        lines.push_back(QLineF(points[i], points[i + 1]));
    }
    lines.push_back(QLineF(points.back(), endPoint));
    painter->drawLines(lines);
}

QRectF Lines::getBoundingRect() const
{
    return scene()->sceneRect();
}

extern "C" Shape* createShape()
{
    return new Lines();
}

#pragma once

#include "shape.h"

class Line : Shape
{
public:
    Line(QPointF startPoint, QPointF endPoint);
    virtual QString getName() const { return name; }
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    static const QString name;
    QPointF startPoint;
    QPointF endPoint;

};

const QString Line::name = "line";

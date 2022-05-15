#pragma once

#include "shape.h"


class Rectangle : public Shape
{
public:
    Rectangle(GlobParams* globParams, QPointF globalStartPoint, QWidget* parent = 0);
    virtual QString getName() const override { return "rectangle"; } // TODO:: return name;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual std::shared_ptr<Shape> clone(QPointF point) const override;

protected:
    virtual QRectF getBoundingRect() const override;
};


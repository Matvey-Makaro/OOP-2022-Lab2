#pragma once

#include "shape.h"


class Rectangle : public Shape
{
public:
    Rectangle();
    virtual QString getName() const override { return "rectangle"; } // TODO:: return name;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual bool isDrawnInTwoClicks() const override { return true; }

protected:
    virtual QRectF getBoundingRect() const override;
};


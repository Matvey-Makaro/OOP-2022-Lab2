#pragma once

#include "ellipse_global.h"
#include "../shape.h"


class ELLIPSE_EXPORT Ellipse : public Shape
{
public:
    Ellipse();
    virtual QString getName() const override { return "ellipse"; } // TODO:: return name;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual bool isDrawnInTwoClicks() const override { return true; }

protected:
    virtual QRectF getBoundingRect() const override;
};

#pragma once

#include "polygon_global.h"
#include "../shape.h"


class POLYGON_EXPORT Polygon : public Shape
{
public:
    Polygon();
    virtual QString getName() const override { return "polygon"; } // TODO:: return name;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual bool isDrawnInTwoClicks() const override { return false; }

protected:
    virtual QRectF getBoundingRect() const override;
};

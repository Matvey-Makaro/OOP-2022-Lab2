#pragma once

#include "lines_global.h"
#include "../shape.h"


class LINES_EXPORT Lines : public Shape
{
public:
    Lines();
    virtual QString getName() const override { return "lines"; } // TODO:: return name;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual bool isDrawnInTwoClicks() const override { return false; }

protected:
    virtual QRectF getBoundingRect() const override;
};

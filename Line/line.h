#pragma once

#include "Line_global.h"
#include "../shape.h"


class LINE_EXPORT Line : public Shape
{
public:
    Line(GlobParams* globParams, QPointF globalStartPoint, QWidget* parent = 0);
    virtual QString getName() const override { return "line"; } // TODO:: return name;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual std::shared_ptr<Shape> clone(QPointF point) const override;


protected:
    virtual QRectF getBoundingRect() const override ;

private:
    //TODO: Сделать чтобы name = line
    static const QString name;

};

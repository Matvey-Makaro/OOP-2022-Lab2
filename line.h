#pragma once

#include "shape.h"

class Line : public Shape
{
public:
    Line();
    virtual QString getName() const override { return "line"; } // TODO:: return name;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual std::shared_ptr<Shape> clone() const override;


protected:
    virtual QRectF getBoundingRect() const override ;

private:
    //TODO: Сделать чтобы name = line
    static const QString name;

};

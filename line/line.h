#ifndef LINE_H
#define LINE_H

#include "line_global.h"
#include "../shape.h"

class LINE_EXPORT Line : public Shape
{
public:
    Line() = default;
    ~Line() override = default;
    virtual QString getName() const override { return "line"; } // TODO:: return name;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual std::shared_ptr<Shape> clone() const override;

protected:
    virtual QRectF getBoundingRect() const override;
};

#endif // LINE_H

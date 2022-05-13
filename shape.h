#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Shape : public QGraphicsItem
{
public:
    Shape();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;
    virtual QString getName() const = 0;

};


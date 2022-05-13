#pragma once

#include "globparams.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Shape : public QGraphicsItem
{
public:
    Shape();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;
    virtual QString getName() const = 0;

protected:
    QColor lineColor;
    QColor brushColor;
    int lineWidth;
    bool brushFlag;
    GlobParams *globs;
    int id;
};


#pragma once

#include "globparams.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <memory>

class Shape : public QObject, public QGraphicsItem
{
public:
    Shape(GlobParams* globParams, QPointF globalStartPoint, QObject* parent = 0);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;
    virtual QString getName() const = 0;
    virtual std::shared_ptr<Shape> clone(QPointF point) const = 0;

    QPointF getStartPoint() const;
    void setStartPoint(const QPointF& value);

    QPointF getEndPoint() const;
    void setEndPoint(const QPointF& value);


protected:
    virtual void updateShape() = 0;

protected:
    GlobParams *globParams;
    QPointF startPoint, endPoint;
    QPointF globalStartPoint;
    QColor penColor;
    QColor brushColor;
    int penWidth;
    bool brushFlag;
    int id;
};


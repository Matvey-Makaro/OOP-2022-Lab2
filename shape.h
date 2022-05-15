#pragma once

#include "globparams.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <memory>
#include <vector>

class Shape : public QObject, public QGraphicsItem
{
public:
    Shape();
    virtual ~Shape() = default;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;
    virtual QRectF boundingRect() const override;
    virtual QString getName() const = 0;
    virtual bool isDrawnInTwoClicks() const = 0;

    QPointF getStartPoint() const;
    void setStartPoint(const QPointF& value);

    QPointF getEndPoint() const;
    void setEndPoint(const QPointF& value);


    QColor getPenColor() const;
    void setPenColor(const QColor &value);

    QColor getBrushColor() const;
    void setBrushColor(const QColor &value);

    int getPenWidth() const;
    void setPenWidth(int value);

    std::vector<QPointF>& getPoints();
    void setPoints(const std::vector<QPointF> &value);
    void addPoint(QPointF point);


    bool getIsCompleted() const;
    void setIsCompleted(bool value);

protected:
    void updateShape();
    virtual QRectF getBoundingRect() const = 0;

protected:
    GlobParams *globParams;
    QPointF startPoint = QPointF(0.0, 0.0), endPoint = QPointF(0.0, 0.0);
    QColor penColor = "white";
    QColor brushColor = "black";
    int penWidth = 5;
    std::vector<QPointF> points;
    bool isCompleted = false;
//    bool brushFlag;
//    int id; //Unused
};

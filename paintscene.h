#pragma once

#include <QGraphicsScene>

class PaintScene : public QGraphicsScene
{
public:
    PaintScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};


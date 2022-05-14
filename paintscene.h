#pragma once

#include "globparams.h"
#include "shape.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <memory>
#include <vector>

class PaintScene : public QGraphicsScene
{
public:
    PaintScene(GlobParams* globParams);
    PaintScene(qreal x, qreal y, qreal width, qreal height, GlobParams* globParams);
    void setShapeToDraw(std::shared_ptr<Shape> shape) { shapeToDraw = shape; }
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    GlobParams* globParams;
    std::shared_ptr<Shape> shapeToDraw;
    std::shared_ptr<Shape> tmpShape;
    std::vector<std::shared_ptr<Shape>> allShapes;
};


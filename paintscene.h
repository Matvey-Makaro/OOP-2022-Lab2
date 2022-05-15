#pragma once

#include "globparams.h"
#include "shape.h"
#include "shapescreator.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <memory>
#include <vector>

class PaintScene : public QGraphicsScene
{
public:
    PaintScene(GlobParams* globParams, ShapesCreator* shapesCreator);
    PaintScene(qreal x, qreal y, qreal width, qreal height, GlobParams* globParams);
    //void setShapeToDraw(std::shared_ptr<Shape> shape) { shapeToDraw = shape; }
    void setShapeToDraw(const QString shapeName) { shapeToDraw = shapeName; }

public slots:
    void undo();
    void redo();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    GlobParams* globParams;
    ShapesCreator* shapesCreator;
    QString shapeToDraw;
    //std::shared_ptr<Shape> shapeToDraw;
    Shape* tmpShape = nullptr;
    std::vector<Shape*> allShapes;
    std::vector<Shape*> undoList;
    std::vector<Shape*> redoList;
};


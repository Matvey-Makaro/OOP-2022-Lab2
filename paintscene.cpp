#include "paintscene.h"

#include <QDebug>

PaintScene::PaintScene(GlobParams *globParams) :
    globParams(globParams)
{

}

PaintScene::PaintScene(qreal x, qreal y, qreal width, qreal height, GlobParams *globParams) :
    QGraphicsScene(x, y, width, height), globParams(globParams)
{

}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    qDebug() << "Mouse press event.\n";
    if(globParams->isDrawAction())
    {
        qDebug() << "Mouse press event event->pos(): " << event->pos();
        tmpShape = shapeToDraw->clone(event->scenePos());
        //tmpShape->setPos(event->pos());
        tmpShape->setStartPoint(event->scenePos());
        tmpShape ->setEndPoint(event->scenePos());
        addItem(tmpShape.get());
        update(0, 0, width(), height());
        qDebug() << tmpShape->getName() << '\n';
    }

}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Mouse move event.\n";
    qDebug() << "Mouse move event->pos(): " << event->pos().x();
    if(globParams->isDrawAction())
    {
        tmpShape->setEndPoint(event->scenePos());
        update(0, 0, width(), height());
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Mouse release event.\n";
    if(globParams->isDrawAction())
    {
        tmpShape->setEndPoint(event->scenePos());
        update(0, 0, width(), height());
        allShapes.push_back(tmpShape);
    }
}

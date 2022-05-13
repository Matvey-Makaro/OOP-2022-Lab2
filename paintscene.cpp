#include "paintscene.h"

#include <QDebug>

PaintScene::PaintScene(qreal x, qreal y, qreal width, qreal height, QObject *parent) :
    QGraphicsScene(x, y, width, height, parent)
{

}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    qDebug() << "Mouse press event.\n";
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Mouse move event.\n";
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Mouse release event.\n";
}

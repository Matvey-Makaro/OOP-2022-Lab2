#pragma once

#include "paintscene.h"
#include "globparams.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsRectItem>
#include <QTimer>

class Paint : public QWidget
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

private:
    void initUi();
    void resizeEvent(QResizeEvent * event);

private slots:
    void timerSlot();

private:
    PaintScene* scene;
    QGraphicsView* view;
    GlobParams* globParams;
    QTimer *timer;
};

#pragma once

#include "paintscene.h"
#include "globparams.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsRectItem>

class Paint : public QWidget
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

private:
    void initUi();

private:
    PaintScene* scene;
    QGraphicsView* view;
    GlobParams* params;
};

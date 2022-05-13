#include "paint.h"

#include <QGridLayout>
#include <QtWidgets>

Paint::Paint(QWidget *parent)
    : QWidget(parent)
{
    initUi();
}

Paint::~Paint()
{
}

void Paint::initUi()
{
    resize(520, 480);
    //setFixedSize(520, 480);
    scene = new PaintScene(510, 470, 510, 470, params, this);
    view = new QGraphicsView(scene);
    auto rect = scene->addRect(0, 0, 120, 120);
    rect->setFlags(QGraphicsItem::ItemIsMovable);
    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->addWidget(view, 0, 0, 10, 10);
    QPushButton* lineBtn = new QPushButton("Line");
    gridLayout->addWidget(lineBtn, 11, 11);
    setLayout(gridLayout);
}


#include "paint.h"
#include "line.h"

#include <QGridLayout>
#include <QtWidgets>
#include <memory>

Paint::Paint(QWidget *parent)
    : globParams(new GlobParams()), QWidget(parent)
{
    globParams->setDrawAction();
    initUi();
}

Paint::~Paint()
{
}

void Paint::initUi()
{
    resize(520, 480);
    //setFixedSize(520, 480);
    //scene = new PaintScene(0, 0, 510, 470, globParams, this);
    scene = new PaintScene(globParams);
    view = new QGraphicsView(scene);
    view->setCursor(Qt::ArrowCursor);
    view->setRenderHint(QPainter::Antialiasing);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);


    globParams->setCurrentBrushColor(Qt::green);
    globParams->setCurrentPenColor(Qt::green);
    globParams->setCurrentPenWidth(5);
    scene->setShapeToDraw(std::make_shared<Line>(globParams, QPointF(100, 100)));
    auto rect = scene->addRect(0, 0, 120, 120);
    rect->setFlags(QGraphicsItem::ItemIsMovable);
    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->addWidget(view, 0, 0, 10, 10);
    QPushButton* lineBtn = new QPushButton("Line");
    gridLayout->addWidget(lineBtn, 11, 11);
    setLayout(gridLayout);
}

void Paint::resizeEvent(QResizeEvent *event)
{
    scene->setSceneRect(0,0, view->width(), view->height());
}

void Paint::timerSlot()
{
    timer->stop();

}

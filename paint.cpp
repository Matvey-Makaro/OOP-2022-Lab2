#include "paint.h"

Paint::Paint(QWidget *parent)
    : QWidget(parent)
{
    resize(520, 480);
    setFixedSize(520, 480);
    scene = new PaintScene(510, 470, 510, 470, this);
    view = new QGraphicsView(scene);
    view->show();
    auto rect = scene->addRect(200, 200, 120, 120);
    rect->setFlags(QGraphicsItem::ItemIsMovable);

}

Paint::~Paint()
{
}


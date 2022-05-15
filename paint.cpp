#include "paint.h"
#include "line.h"
#include "rectangle.h"

#include <QGridLayout>
#include <QtWidgets>
#include <QShortcut>
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
    //scene->setShapeToDraw(std::make_shared<Line>());
    scene->setShapeToDraw(std::make_shared<Rectangle>());

    QSlider *lineWidth = new QSlider(Qt::Horizontal, this);
    lineWidth->setRange(0, 10);
    lineWidth->setTickInterval(1);
    connect(lineWidth, &QSlider::valueChanged, this, &Paint::updateLineWidth);

    QPushButton *penColorButton = new QPushButton(this);
    penColorButton->setText("Select pen color");
    connect(penColorButton, &QPushButton::clicked, this, &Paint::selectPenColor);

    QPushButton *brushColorButton = new QPushButton(this);
    brushColorButton->setText("Select brush color");
    connect(brushColorButton, &QPushButton::clicked, this, &Paint::selectBrushColor);

    connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this),
            &QShortcut::activated, scene, &PaintScene::undo);

    connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this),
            &QShortcut::activated, scene, &PaintScene::redo);

    auto rect = scene->addRect(0, 0, 120, 120);
    rect->setFlags(QGraphicsItem::ItemIsMovable);

    QPushButton* lineBtn = new QPushButton("Line");
    QComboBox *shapesList = new QComboBox(this);
    shapesNames << "line" << "square";
    shapesList->addItems(shapesNames);
    connect(shapesList, &QComboBox::currentTextChanged, this, &Paint::updateCurrentShape);

    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->addWidget(view, 2, 0, 10, 10);
    gridLayout->addWidget(penColorButton, 0, 0, 1, 1);
    gridLayout->addWidget(brushColorButton, 1, 0, 1, 1);
    gridLayout->addWidget(lineWidth, 0, 1, 1, 1);
    gridLayout->addWidget(shapesList, 0, 11, 2, 1);
    gridLayout->addWidget(lineBtn, 11, 11);
    setLayout(gridLayout);
}

void Paint::resizeEvent(QResizeEvent *event)
{
    scene->setSceneRect(0,0, view->width(), view->height());
}

QColor Paint::getColorFromUser() const
{
    QColorDialog dialog;
    QColor color = dialog.getColor();
    return color;
}

void Paint::updateLineWidth(int value)
{
    globParams->setCurrentPenWidth(value);
}

void Paint::updateCurrentShape(QString currShape)
{
    qDebug() << "Update current shape. New shape: " << currShape << '\n';
}

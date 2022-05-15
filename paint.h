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
#include <QString>
#include <QStringList>

class Paint : public QWidget
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

private:
    void initUi();
    void resizeEvent(QResizeEvent * event);
    QColor getColorFromUser() const;

protected slots:
    void updateLineWidth(int value);
    void selectPenColor() {  globParams->setCurrentPenColor(getColorFromUser()); }
    void selectBrushColor() { globParams->setCurrentBrushColor(getColorFromUser()); }
    void updateCurrentShape(QString currShape);

private slots:
    //void timerSlot();   // UNUSED

private:
    PaintScene* scene;
    QGraphicsView* view;
    GlobParams* globParams;
    QTimer *timer;  // UNUSED
    QStringList shapesNames;
};

#pragma once

#include "paintscene.h"
#include "globparams.h"
#include "shapescreator.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsRectItem>
#include <QString>
#include <QStringList>
#include <memory>

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
    void moveBtnClicked();

private:
    PaintScene* scene;  // add delete scene
    QGraphicsView* view;    //add delete view
    GlobParams* globParams;
    ShapesCreator* shapesCreator;   //add delete shapesCreator
    QStringList shapesNames;
};

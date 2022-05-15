#include "globparams.h"

GlobParams::GlobParams()
{

}

void GlobParams::setDrawAction()
{
    setAllFlagsFalse();
    drawFlag = true;
}

void GlobParams::setMoveAction()
{
    setAllFlagsFalse();
    moveFlag = true;
}

void GlobParams::setAllFlagsFalse()
{
    // TODO: делать сделть все флаги равными false
    drawFlag = false;
    moveFlag = false;
}

int GlobParams::getCurrentPenWidth() const
{
    return currentPenWidth;
}

void GlobParams::setCurrentPenWidth(int value)
{
    currentPenWidth = value;
}

QColor GlobParams::getCurrentBrushColor() const
{
    return currentBrushColor;
}

void GlobParams::setCurrentBrushColor(const QColor &value)
{
    currentBrushColor = value;
}

QColor GlobParams::getCurrentPenColor() const
{
    return currentPenColor;
}

void GlobParams::setCurrentPenColor(const QColor &value)
{
    currentPenColor = value;
}

#pragma once

#include <QColor>
#include <QPen>


class GlobParams
{
public:
    // Можно использовать паттерн синглтон
    GlobParams();
    bool isDrawAction() const { return drawFlag; }
    void setDrawAction();

    QColor getCurrentPenColor() const;
    void setCurrentPenColor(const QColor &value);

    QColor getCurrentBrushColor() const;
    void setCurrentBrushColor(const QColor &value);

    int getCurrentPenWidth() const;
    void setCurrentPenWidth(int value);

private:
    void setAllFlagsFalse();
private:
    bool drawFlag = false;

    QColor currentPenColor;
    QColor currentBrushColor;
    int currentPenWidth;
};


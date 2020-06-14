#pragma once

#include <QtWidgets/QWidget>
#include "ui_ballsortgui.h"

class BallSortGUI : public QWidget
{
    Q_OBJECT
public:
    BallSortGUI(QWidget *parent = Q_NULLPTR);
    virtual void paintEvent(QPaintEvent* event);

private:
    Ui::BallSortGUIClass ui;
    void drawTubes(QPainter& painter, int num);
};

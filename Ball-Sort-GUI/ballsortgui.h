#pragma once

#include <QtWidgets/QWidget>
#include "ui_ballsortgui.h"
#include<qpainter.h>
#include<QHBoxLayout>
#include<qlabel.h>
#include<QHBoxLayout>
#include<vector>
#include<qgridlayout.h>
#include<qpropertyanimation.h>
#include<map>
#include"../Ball-Sort-Puzzle-Solver/Game.h"

class BallSortGUI : public QWidget
{
    Q_OBJECT
public:
    BallSortGUI(QWidget *parent = Q_NULLPTR);
    virtual void paintEvent(QPaintEvent* event);
    static void initiateScreenAndTubes();
    static Game g;

private:
    Ui::BallSortGUIClass ui;
    static std::vector<QLabel*> tubes;
    QPropertyAnimation* animation = NULL;
    void drawBall(QPainter& painter ,int tubeNum, int index, QColor color);
};

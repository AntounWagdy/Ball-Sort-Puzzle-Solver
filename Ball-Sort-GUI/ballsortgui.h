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
#include <QTimer>
#include <qobject.h>
#include"../Ball-Sort-Puzzle-Solver/Game.h"
#include"../Ball-Sort-Puzzle-Solver/GameSolver.h"

class BallSortGUI : public QWidget
{
    Q_OBJECT
public:
    BallSortGUI(QWidget *parent = Q_NULLPTR);
    virtual void paintEvent(QPaintEvent* event);
    static void initiateScreenAndTubes();
    static Game g;
    static std::vector<std::pair<int, int>> solution;

public slots:
    void makeMove()
    {
        if (solIndex == solution.size()) {
            return;
        }
        g.makeMove(solution[solIndex].first, solution[solIndex].second);
        solIndex++;
        repaint();
    };
private:
    Ui::BallSortGUIClass ui;
    static std::vector<QLabel*> tubes;
    void drawBall(QPainter& painter ,int tubeNum, int index, QColor color);
    QTimer *timer;
    int solIndex = 0;
};

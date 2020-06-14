#include "ballsortgui.h"
#include<qpainter.h>
BallSortGUI::BallSortGUI(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setStyleSheet("background-color : white;");
    QWidget::showFullScreen();
 }

void BallSortGUI::paintEvent(QPaintEvent* event)
{
    QColor red("#FF0000");

    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    drawTubes(painter,5);

    QBrush brush(red,Qt::SolidPattern);
    painter.setBrush(brush);
    

    //painter.drawEllipse(QRect(20,20,100,100));
    
}

void BallSortGUI::drawTubes(QPainter &painter, int num)
{
    if (num / 2 > 2) {
    
        // two lines of tubes

    }
    else {
        // one line of tubes
    }
    painter.drawImage(QPoint(0, 0), QImage("../res/tube.png").scaled(QSize(100,300)));
}

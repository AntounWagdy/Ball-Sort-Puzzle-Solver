#include "ballsortgui.h"

std::vector<QLabel*> BallSortGUI::tubes;
Game BallSortGUI::g;

BallSortGUI::BallSortGUI(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setStyleSheet("background-color : white;");
    QWidget::showFullScreen();
 }

void BallSortGUI::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    Tube temp;
    char b;
    int index;

    for (size_t i = 0; i < g.getNumTubes(); i++)
    {
        Tube temp = g.tubes[i];
        index = temp.size()-1;
        while (!temp.isEmpty()) {
            temp.pop(b);
            drawBall(painter, i, index--, Qt::GlobalColor(6+((b-'A')%14)));
        }
    }
    if (!animation) {
        animation = new QPropertyAnimation(tubes[0], "pos");
        animation->setDuration(500);
        animation->setStartValue(tubes[0]->pos());
        animation->setStartValue(QPoint(tubes[0]->pos().x(), tubes[0]->pos().y() - 100));
        animation->start();
    }
    if (animation->currentTime() == 500) {
        animation = NULL;
    }

}




void BallSortGUI::initiateScreenAndTubes()
{
    int num = g.getNumTubes();
    QWidget *wrapper = new QWidget;

    QGridLayout *layout = new QGridLayout(wrapper);
    layout->setMargin(250);
    QPixmap qpix = QPixmap("../res/tube.png").scaled(100, 250);
    

    if (num / 2 > 2) {
        // two lines of tubes
        int line1 = ceil(num / 2.0);
        for (int i = 0; i < line1; i++)
        {
            QLabel* img = new QLabel();
            img->setPixmap(qpix);
            layout->addWidget(img,0,i);
            tubes.push_back(img);
        }
        for (int i = 0; i < num-line1; i++)
        {
            QLabel* img = new QLabel();
            img->setPixmap(qpix);
            layout->addWidget(img,1,i);
            tubes.push_back(img);
        }

    }
    else {
        // one lines of tubes

        for (int i = 0; i < num; i++)
        {
            QLabel* img = new QLabel();
            img->setPixmap(qpix);
            layout->addWidget(img, 0, i);
            tubes.push_back(img);
        }
    }
    BallSortGUI* overlay = new BallSortGUI();
    overlay->setParent(wrapper);
    wrapper->showFullScreen();
}

void BallSortGUI::drawBall(QPainter& painter, int tubeNum, int index, QColor color)
{
    painter.setBrush(QBrush(color, Qt::SolidPattern));
    int x = tubes[tubeNum]->pos().x() + 50;
    int y = tubes[tubeNum]->pos().y() + 230 - (52*index);
    painter.drawEllipse(QPoint(x, y), 25, 25);
}

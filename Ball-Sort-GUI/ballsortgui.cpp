#include "ballsortgui.h"

std::vector<QLabel*> BallSortGUI::tubes;
Game BallSortGUI::g;
std::vector<std::pair<int, int>> BallSortGUI::solution;
QColor colors[] = { QColor(128,0,0) ,QColor(170,110,40),QColor(128,128,0) ,QColor(0,128,128) ,QColor(0,0,128),QColor(0,0,0)
                    ,QColor(230,25,75) ,QColor(245,130,48) ,QColor(225,225,25) ,QColor(210,245,60),QColor(60,180,75),QColor(70,240,240)
                    ,QColor(0,130,200),QColor(145,30,180),QColor(240,50,230),QColor(128,128,128),QColor(250,190,212),QColor(255,215,180)
                    ,QColor(255,250,200),QColor(170,255,195),QColor(220,190,255),QColor(255,255,255)
                    ,QColor(255,0,0),QColor(0,255,0),QColor(0,0,255),QColor(0,0,128) };

BallSortGUI::BallSortGUI(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setStyleSheet("background-color : white;");
    QWidget::showFullScreen();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(makeMove()));
    timer->start(300);
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
            drawBall(painter, i, index--, colors[b-'A']);
        }
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
    GameSolver solver;
    solution = solver.iteration_solve_with_heuristic(g);
}

void BallSortGUI::drawBall(QPainter& painter, int tubeNum, int index, QColor color)
{
    painter.setBrush(QBrush(color, Qt::SolidPattern));
    int x = tubes[tubeNum]->pos().x() + 50;
    int y = tubes[tubeNum]->pos().y() + 230 - (52*index);
    painter.drawEllipse(QPoint(x, y), 25, 25);
}

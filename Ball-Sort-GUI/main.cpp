#include "ballsortgui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //BallSortGUI w;
    //w.show();
    BallSortGUI::g = Game("../tests/L107.txt");
    BallSortGUI::initiateScreenAndTubes();
    return a.exec();
}

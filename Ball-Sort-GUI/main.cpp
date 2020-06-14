#include "ballsortgui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BallSortGUI w;
    w.show();
    return a.exec();
}

#include <QApplication>
#include "multitimer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Multitimer multitimer;
    multitimer.showMaximized();
    return 0;
}

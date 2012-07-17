#include <QApplication>
#include <QTextCodec>
#include "multitimer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Multitimer");
    app.setApplicationVersion("v0.1");
    app.setOrganizationName("Noname043");

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    Multitimer multitimer;
    multitimer.setWindowTitle(QString("%1 %2").arg(app.applicationName(), app.applicationVersion()));
    multitimer.showMaximized();

    return app.exec();
}

#include <QApplication>
#include <QTextCodec>
#include <QTranslator>
#include <QLocale>
#include "multitimer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Multitimer");
    app.setApplicationVersion("v0.1");
    app.setOrganizationName("Noname043");

    QTranslator translator;
    translator.load(QString(":/Multitimer_") + QLocale::system().name());
    app.installTranslator(&translator);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    Multitimer multitimer;
    multitimer.setWindowTitle(QString("%1 %2").arg(app.applicationName(), app.applicationVersion()));
    multitimer.showMaximized();

    return app.exec();
}

#include "multitimer.h"
#include <QApplication>
#include <QGridLayout>
#include <QS60Style>

Multitimer::Multitimer(QWidget *parent):
    QWidget(parent),
    _tabWidget(new QTabWidget(this)),
    _helpText(new QTextEdit(this)),
    _quitAction(new QAction(tr("Exit"), this)),
    _optionsAction(new QAction(tr("Options"), this)),
    _newAction(new QAction(tr("New"), this)),
    _deleteAction(new QAction(tr("Delete"), this))
{
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(_tabWidget);

    _helpText->setReadOnly(true);
    _helpText->setHtml(tr("Select <b>Options->New</b> to create new counter. You will be asked to name it.<br>"
                          "Tap the counter to change its time. When counter is reset it works like stopwatch. "
                          "If it is non zero it works as timer.<br>"
                          "You may remove current counter with <b>Options->Delete</b>."));
    _tabWidget->addTab(_helpText, "Help");

    addAction(_quitAction);
    addAction(_optionsAction);
#ifndef S60V5
    _quitAction->setIcon(qApp->style()->standardPixmap(static_cast<QStyle::StandardPixmap>(SP_CustomToolBarBack)));
    _optionsAction->setIcon(qApp->style()->standardPixmap(QStyle::SP_TitleBarMenuButton));
#endif
    _quitAction->setSoftKeyRole(QAction::NegativeSoftKey);
    _optionsAction->setSoftKeyRole(QAction::PositiveSoftKey);
    QMenu *menu = new QMenu(this);
    menu->addAction(_newAction);
    menu->addAction(_deleteAction);
    menu->addAction(_quitAction);
    _optionsAction->setMenu(menu);

    connect(_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(_newAction, SIGNAL(triggered()), this, SLOT(newCounter()));
    connect(_deleteAction, SIGNAL(triggered()), this, SLOT(deleteCounter()));
}

Multitimer::~Multitimer()
{}

void Multitimer::newCounter()
{

}

void Multitimer::deleteCounter()
{

}

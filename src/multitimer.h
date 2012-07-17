#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QInputDialog>
#include <QMenu>
#include <QAction>

//! This class will be responsible for main window.
//! It will allow user to create or delete tabs with counters.
//! Help tab shouldn't be deleted.
class Multitimer: public QWidget
{
    Q_OBJECT
public:

    //! Initializes UI and creates signal-slot connections.
    Multitimer(QWidget *parent = 0);
    ~Multitimer();

private slots:
    //! Will be invoked after new counter requested.
    //! Should ask about new counter's name, add it to _tabWidget
    //! and switch to it.
    void newCounter();

    //! Removes current counter (tab). Shouldn't remove help tab.
    void deleteCounter();

private:
    QTabWidget *_tabWidget;
    QTextEdit *_helpText;
    QAction *_quitAction;
    QAction *_optionsAction;
    QAction *_newAction;
    QAction *_deleteAction;
};

#endif // WIDGET_H

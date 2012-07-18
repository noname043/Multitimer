#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>
#include "ui_counter.h"

//! This class will work as timer or stopwatch. It will be placed in
//! Multitimer's _tabWidget.
class Counter: public QWidget
{
    Q_OBJECT
public:
    //! Counter's mode.
    enum Mode
    {
        Timer,    //!< Counter works as timer.
        Stopwatch //!< Counter works as stopwatch.
    };

    //! Initializes UI and creates signal-slot connections.
    //! \param  parent  Widget's parent.
    Counter(QWidget *parent = 0);
    ~Counter();

private slots:
    //! This slot will be invoked after click on _counterLabel.
    //! It will show time editor.
    void editCounter();

    //! Starts counter depending on mode.
    void start();

    //! Pauses counter.
    void pause();

    //! Sets counter to 0.
    void reset();
    
private:
    Ui::Counter *_ui;
};

#endif // COUNTER_H

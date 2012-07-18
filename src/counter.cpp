#include "counter.h"
#include <QApplication>
#include <QStyle>
#include <QSpacerItem>

Counter::Counter(QWidget *parent):
    QWidget(parent),
    _ui(new Ui::Counter)
{
    _ui->setupUi(this);
    _ui->start->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaPlay));
    _ui->pause->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaPause));
    _ui->pause->setVisible(false);
    _ui->reset->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaStop));

    // TODO: replace QLabel with something that handles mouse events.
    connect(_ui->counterLabel, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(editCounter()));
    connect(_ui->start, SIGNAL(clicked()), this, SLOT(start()));
    connect(_ui->pause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(_ui->reset, SIGNAL(clicked()), this, SLOT(reset()));
}

Counter::~Counter()
{}

void Counter::editCounter()
{}

void Counter::start()
{}

void Counter::pause()
{}

void Counter::reset()
{}

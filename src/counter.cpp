#include "counter.h"
#include <QApplication>
#include <QStyle>
#include <QSpacerItem>

Counter::Counter(QWidget *parent):
    QWidget(parent),
    _ui(new Ui::Counter),
    _timer(new QTimer(this)),
    _updater(new QTimer(this))
{
    _ui->setupUi(this);
    _ui->start->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaPlay));
    _ui->pause->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaPause));
    _ui->pause->setVisible(false);
    _ui->reset->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaStop));

    _timer->setSingleShot(true);
    _updater->setSingleShot(false);
    _updater->setInterval(10);

    // TODO: replace QLabel with something that handles mouse events.
    connect(_ui->counterLabel, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(editCounter()));
    connect(_ui->start, SIGNAL(clicked()), this, SLOT(start()));
    connect(_ui->pause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(_ui->reset, SIGNAL(clicked()), this, SLOT(reset()));
    connect(_updater, SIGNAL(timeout()), this, SLOT(updateLabel()));
}

Counter::~Counter()
{}

void Counter::editCounter()
{}

void Counter::start()
{
    _ui->pause->show();
    _ui->start->hide();
    _startTime = QDateTime::currentMSecsSinceEpoch();
    _updater->start();
}

void Counter::pause()
{
    _ui->pause->hide();
    _ui->start->show();
    _updater->stop();
    updateLabel();
}

void Counter::reset()
{
    _ui->counterLabel->setText("00:00:00.000");
    _updater->stop();
    _ui->pause->hide();
    _ui->start->show();
}

void Counter::updateLabel()
{
    QDateTime time = QDateTime::fromMSecsSinceEpoch(QDateTime::currentMSecsSinceEpoch() - _startTime).toUTC();
    _ui->counterLabel->setText(time.toString("hh:mm:ss.zzz"));
}

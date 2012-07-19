#include "counter.h"
#include <QApplication>
#include <QStyle>
#include <QSpacerItem>
#include <QMessageBox>

Counter::Counter(QWidget *parent):
    QWidget(parent),
    _ui(new Ui::Counter),
    _timer(new QTimer(this)),
    _updater(new QTimer(this)),
    _audioOutput(new Phonon::AudioOutput(Phonon::MusicCategory, this)),
    _mediaObject(new Phonon::MediaObject(this))
{
    _ui->setupUi(this);
    _ui->start->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaPlay));
    _ui->pause->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaPause));
    _ui->pause->setVisible(false);
    _ui->reset->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaStop));

    _timer->setSingleShot(true);
    _updater->setSingleShot(false);
    _updater->setInterval(10);

    Phonon::createPath(_mediaObject, _audioOutput);
    Phonon::MediaSource *source = new Phonon::MediaSource(":/timer.mp3");
    qDebug(QString::number(source->type()).toStdString().c_str());
    _mediaObject->setCurrentSource(*source);

    // TODO: replace QLabel with something that handles mouse events.
    connect(_ui->counterLabel, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(editCounter()));
    connect(_ui->start, SIGNAL(clicked()), this, SLOT(start()));
    connect(_ui->pause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(_ui->reset, SIGNAL(clicked()), this, SLOT(reset()));
    connect(_updater, SIGNAL(timeout()), this, SLOT(updateLabel()));
    connect(_timer, SIGNAL(timeout()), this, SLOT(reset()));
    connect(_timer, SIGNAL(timeout()), this, SLOT(alarm()));
    connect(_timer, SIGNAL(timeout()), _mediaObject, SLOT(play()));
    connect(_ui->reset, SIGNAL(clicked()), _mediaObject, SLOT(stop()));
}

Counter::~Counter()
{}

void Counter::editCounter()
{}

void Counter::start()
{
    qint64 time = timeFromString(_ui->counterLabel->text());
    // Stopwatch mode?
    if (!time)
    {
        _mode = Stopwatch;
        _startTime = QDateTime::currentMSecsSinceEpoch();
    }
    // ...or timer mode?
    else
    {
        _mode = Timer;
        _endTime = QDateTime::currentMSecsSinceEpoch() + time;
        _timer->start(time);
    }
    _ui->pause->show();
    _ui->start->hide();
    _updater->start();
}

void Counter::pause()
{
    _ui->pause->hide();
    _ui->start->show();
    _updater->stop();
    _timer->stop();
    updateLabel();
}

void Counter::reset()
{
    _ui->counterLabel->setText("00:00:00.000");
    _updater->stop();
    _timer->stop();
    _ui->pause->hide();
    _ui->start->show();
}

void Counter::updateLabel()
{
    QDateTime time;
    if (_mode == Stopwatch)
        time = QDateTime::fromMSecsSinceEpoch(QDateTime::currentMSecsSinceEpoch() - _startTime).toUTC();
    else time = QDateTime::fromMSecsSinceEpoch(_endTime - QDateTime::currentMSecsSinceEpoch()).toUTC();
    _ui->counterLabel->setText(time.toString("hh:mm:ss.zzz"));
}

void Counter::alarm()
{
    this->raise();
}

qint64 Counter::timeFromString(const QString &text)
{
    qint64 t = 0;
    QStringList list = text.split('.');
    t += list[1].toInt(); // Miliseconds
    list = list[0].split(':');
    t += list[2].toInt() * 1000; // Seconds
    t += list[1].toInt() * 60 * 1000; // Minutes
    t += list[0].toInt() * 60 * 60 * 1000; // Hours
    return t;
}

#include "settingsdialog.h"
#include <QS60Style>
#include <QFileDialog>

SettingsDialog::SettingsDialog(Phonon::AudioOutput *output, Phonon::MediaObject *object, QWidget *parent):
    QDialog(parent),
    _ui(new Ui::SettingsDialog),
    _volume(new Phonon::VolumeSlider(output, this)),
    _backAction(new QAction(tr("Back"), this)),
    _output(output),
    _object(object)
{
    _ui->setupUi(this);

    _ui->verticalLayout->addWidget(_volume);

    addAction(_backAction);
#if QT_VERSION >= 0x040704
    _backAction->setIcon(qApp->style()->standardIcon(static_cast<QStyle::StandardPixmap>(SP_CustomToolBarBack)));
#endif
    _backAction->setSoftKeyRole(QAction::NegativeSoftKey);
    QAction *tmp = new QAction(this);
    addAction(tmp);
    tmp->setSoftKeyRole(QAction::PositiveSoftKey);

    connect(_ui->defaultAlarm, SIGNAL(clicked()), this, SLOT(setDefaultAlarm()));
    connect(_ui->customAlarm, SIGNAL(clicked()), this, SLOT(setCustomAlarm()));
    connect(_ui->selectAlarm, SIGNAL(clicked()), this, SLOT(selectAlarmFile()));
    connect(_backAction, SIGNAL(triggered()), this, SLOT(close()));

    //setModal(true);
    this->move(0, 26);
}

SettingsDialog::~SettingsDialog()
{
    delete _ui;
}

void SettingsDialog::setDefaultAlarm()
{
    _object->setCurrentSource(Phonon::MediaSource("timer.mp3"));
}

void SettingsDialog::setCustomAlarm()
{
    if (_ui->selectAlarm->text() != "...")
    {
        _object->setCurrentSource(Phonon::MediaSource(_ui->selectAlarm->text()));
    }
    else selectAlarmFile();
}

void SettingsDialog::selectAlarmFile()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select alarm"), "", "*.mp3;;*.wav;;*.ogg");
    if (file.isEmpty())
    {
        if (_ui->selectAlarm->text() == "...")
            _ui->defaultAlarm->setChecked(true);
        return;
    }
    _ui->selectAlarm->setText(file);
    setCustomAlarm();
}

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <AudioOutput>
#include <MediaObject>
#include <VolumeSlider>
#include <QAction>
#include "ui_settingsdialog.h"

class SettingsDialog: public QDialog
{
    Q_OBJECT
public:
    //! Initializes UI and creates signal-slot connections. Needs Counter's
    //! AutioOutput to create Phonon::VolumeSlider.
    //! \param  output  Counter's audio output.
    //! \param  object  Parent's media object.
    //! \param  parent  Dialog's parent.
    SettingsDialog(Phonon::AudioOutput *output, Phonon::MediaObject *object, QWidget *parent = 0);
    ~SettingsDialog();

private slots:
    //! This slot will be invoked after _ui->defaultAlarm's clicked().
    //! It will set default alarm sound.
    void setDefaultAlarm();

    //! This slot will be invoked after _ui->customAlarm's clicked() and
    //! after every change of alarm sound file. When it's invoked it should
    //! check if _ui->selectAlarm button is set to "...". If so - have to
    //! select new file with selectAlarmFile().
    void setCustomAlarm();

    //! This slot will be invoked to select new alarm sound file.
    //! It will invoke setCustomAlarm() or leave previous alarm file.
    //! If user cancels and _ui->selectAlarm is set to "..." then have to
    //! go back to default alarm.
    void selectAlarmFile();

private:
    Ui::SettingsDialog *_ui;
    Phonon::VolumeSlider *_volume;
    QAction *_backAction;
    Phonon::AudioOutput *_output;
    Phonon::MediaObject *_object;
};

#endif // SETTINGSDIALOG_H

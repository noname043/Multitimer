#-------------------------------------------------
#
# Project created by QtCreator 2012-07-17T21:40:12
#
#-------------------------------------------------

QT       += core gui phonon

TARGET = Multitimer
TEMPLATE = app

ICON = res/multitimer.svg
VERSION = 1.0.0

SOURCES += src/main.cpp \
    src/multitimer.cpp \
    src/counter.cpp \
    src/settingsdialog.cpp \
    src/customlabel.cpp \
    src/editordialog.cpp

HEADERS  += \
    src/multitimer.h \
    src/counter.h \
    src/settingsdialog.h \
    src/customlabel.h \
    src/editordialog.h

#CONFIG += mobility
#MOBILITY =

symbian {
    TARGET.UID3 = 0x2006b47d
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000

    alarm.sources = res/timer.mp3
    DEPLOYMENT += alarm
}

OTHER_FILES += \
    README.txt

FORMS += \
    ui/counter.ui \
    ui/settingsdialog.ui \
    ui/editordialog.ui

RESOURCES += \
    res/res.qrc

CODECFORTR = UTF-8
TRANSLATIONS += res/Multitimer_pl.ts

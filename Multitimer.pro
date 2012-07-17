#-------------------------------------------------
#
# Project created by QtCreator 2012-07-17T21:40:12
#
#-------------------------------------------------

QT       += core gui

TARGET = Multitimer
TEMPLATE = app


SOURCES += src/main.cpp \
    src/multitimer.cpp

HEADERS  += \
    src/multitimer.h

#CONFIG += mobility
#MOBILITY =

symbian {
    TARGET.UID3 = 0xec73e7e6
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES += \
    README.txt

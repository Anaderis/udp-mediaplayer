#-------------------------------------------------
#
# Project created by QtCreator 2024-07-03T09:19:52
#
#-------------------------------------------------

QT       += core network multimedia multimediawidgets qml quick

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = networking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        udpsockethandler.cpp

HEADERS  += mainwindow.h \
    udpsockethandler.h

FORMS    += mainwindow.ui

DISTFILES += \
    main.qml

RESOURCES += qml.qrc

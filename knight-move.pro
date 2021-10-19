#-------------------------------------------------
#
# Project created by QtCreator 2021-10-15T17:27:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = knight-move
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    knight.cpp \
    main.cpp \
    pos_init.cpp

HEADERS  += mainwindow.h \
    knight.h \
    pos_init.h

FORMS    += mainwindow.ui

RESOURCES += \
    knight-resources.qrc

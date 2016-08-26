#-------------------------------------------------
#
# Project created by QtCreator 2016-08-10T21:43:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    platform.cpp \
    myscene.cpp \
    myview.cpp \
    ball.cpp \
    tile.cpp \
    graphicsitemdrawimage.cpp

HEADERS  += mainwindow.h \
    platform.h \
    myscene.h \
    myview.h \
    ball.h \
    tile.h \
    graphicsitemdrawimage.h

FORMS    += mainwindow.ui

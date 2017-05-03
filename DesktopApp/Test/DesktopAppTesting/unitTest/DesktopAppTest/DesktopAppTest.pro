#-------------------------------------------------
#
# Project created by QtCreator 2017-04-17T17:25:35
#
#-------------------------------------------------

QT       += core gui
QT += network
QT += widgets testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesktopAppTest
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    httprequestworker.cpp \
    testgui.cpp

HEADERS  += mainwindow.h \
    httprequestworker.h \
    jsonkeys.h

FORMS    += mainwindow.ui

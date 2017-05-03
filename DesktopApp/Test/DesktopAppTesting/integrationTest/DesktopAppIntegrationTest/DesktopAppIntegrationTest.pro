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
    httprequestworker.cpp \
    httprequestworker.cpp \
    mainwindow.cpp \
    main.cpp \
    randomfact.cpp

HEADERS  += \
    httprequestworker.h \
    jsonkeys.h \
    httprequestworker.h \
    jsonkeys.h \
    mainwindow.h \
    randomfact.h

FORMS    += \
    mainwindow.ui \
    randomfact.ui

#-------------------------------------------------
#
# Project created by QtCreator 2016-09-06T08:22:10
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentDataBase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    globaldef.h \
    client.h

FORMS    += mainwindow.ui \
    logindialog.ui

DISTFILES +=

RESOURCES +=

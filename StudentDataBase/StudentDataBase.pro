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
    mainwindow/mainwindow.cpp \
    client/client.cpp \
    messagehandler/messagehandler.cpp \
    logindialog/logindialog.cpp

HEADERS  += client/client.h \
    messagehandler/messagehandler.h \
    logindialog/logindialog.h \
    mainwindow/mainwindow.h\
    protocol.h \
    globaldef.h


FORMS    += \
    logindialog/logindialog.ui
    mainwindow/mainwindow.ui

RESOURCES += \
    res.qrc

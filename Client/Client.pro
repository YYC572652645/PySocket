#-------------------------------------------------
#
# Project created by QtCreator 2017-08-19T08:22:10
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow/mainwindow.cpp \
    client/client.cpp \
    messagehandler/messagehandler.cpp \
    logindialog/logindialog.cpp \
    personinfodialog/personinfodialog.cpp

HEADERS  += client/client.h \
    messagehandler/messagehandler.h \
    logindialog/logindialog.h \
    mainwindow/mainwindow.h\
    protocol.h \
    globaldef.h \
    personinfodialog/personinfodialog.h


FORMS    += \
    logindialog/logindialog.ui \
    mainwindow/mainwindow.ui \
    personinfodialog/personinfodialog.ui

RESOURCES += \
    res.qrc

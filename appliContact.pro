#-------------------------------------------------
#
# Project created by QtCreator 2016-11-17T10:49:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = appliContact
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    contact.cpp \
    dialogaddcontact.cpp \
    dialogupdatecontact.cpp

HEADERS  += mainwindow.h \
    contact.h \
    dialogaddcontact.h \
    dialogupdatecontact.h

FORMS    += mainwindow.ui \
    dialogaddcontact.ui \
    dialogupdatecontact.ui

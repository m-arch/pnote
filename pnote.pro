#-------------------------------------------------
#
# Project created by QtCreator 2014-10-05T11:45:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pnote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbconnect.cpp \
    dbsetup.cpp \
    utilities.cpp \
    menuwindow.cpp \
    notewindow.cpp \
    userswindow.cpp \
    user.cpp \
    usercar.cpp \
    initialize.cpp

HEADERS  += mainwindow.h \
    dbconnect.h \
    dbsetup.h \
    utilities.h \
    menuwindow.h \
    notewindow.h \
    userswindow.h \
    user.h \
    usercar.h \
    initialize.h

FORMS    += mainwindow.ui \
    menuwindow.ui \
    notewindow.ui \
    userswindow.ui

OTHER_FILES +=

RESOURCES += \
    mainwindow.qrc


#-------------------------------------------------
#
# Project created by QtCreator 2014-10-05T11:45:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pnote
TEMPLATE = app

LIBS += -lhpdf -lm -lz

SOURCES += main.cpp\
    initialize.cpp \
    GUIWindows/mainwindow.cpp \
    GUIWindows/menuwindow.cpp \
    GUIWindows/notewindow.cpp \
    GUIWindows/userswindow.cpp \
    logic/dbconnect.cpp \
    logic/dbsetup.cpp \
    logic/user.cpp \
    logic/usercar.cpp \
    logic/utilities.cpp \
    logic/generatepdf.cpp \
    logic/dbsearch.cpp \
    GUIWindows/cartab.cpp \
    GUIWindows/vinlookup.cpp

HEADERS  += initialize.h \
    GUIWindows/mainwindow.h \
    GUIWindows/menuwindow.h \
    GUIWindows/notewindow.h \
    GUIWindows/userswindow.h \
    logic/dbconnect.h \
    logic/dbsetup.h \
    logic/user.h \
    logic/usercar.h \
    logic/utilities.h \
    extensions.h \
    logic/generatepdf.h \
    logic/dbsearch.h \
    GUIWindows/cartab.h \
    GUIWindows/vinlookup.h

FORMS    += GUIWindows/mainwindow.ui \
    GUIWindows/menuwindow.ui \
    GUIWindows/notewindow.ui \
    GUIWindows/userswindow.ui \
    GUIWindows/cartab.ui \
    GUIWindows/vinlookup.ui

OTHER_FILES +=

RESOURCES += \
    mainwindow.qrc


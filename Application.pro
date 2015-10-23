#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T14:11:56
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Application
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        menubar.cpp \
        user.cpp \
        requests.cpp

HEADERS  += mainwindow.hpp \
            menubar.hpp \
            user.hpp \
            requests.hpp

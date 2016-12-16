#-------------------------------------------------
#
# Project created by QtCreator 2016-12-16T17:26:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = custom_plot
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    qcustomplot.cpp

HEADERS  += dialog.h \
    qcustomplot.h

FORMS    += dialog.ui

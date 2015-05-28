#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T23:57:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tamagotchi.cpp \
    Estructuras/pila.cpp \
    granja.cpp \
    actividad.cpp \
    create.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    tamagotchi.h \
    Estructuras/pila.h \
    granja.h \
    actividad.h \
    create.h \
    settings.h

FORMS    += mainwindow.ui \
    create.ui \
    settings.ui

#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Historique avec QStateMachine"
# exemple : QHistoryState
#           etape 04 : historique + interruption message
# Daniel Génon MAR 2022 Revin
# version : 1 : 31/03/2022 version QT 5.15.2 6.21 6.22
#-------------------------------------------------

QT += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += statemachine

TARGET = etape04
TEMPLATE = app
CONFIG += c++11

SOURCES += \
    deplacement.cpp \
    main.cpp \
    ../objetimage.cpp \
    ../sequence.cpp \
    ../vue.cpp \
    ../zoneanime.cpp \
    fenetre.cpp \
    pause.cpp \
    scene.cpp \

HEADERS += \
    ../objetimage.h \
    ../sequence.h \
    ../vue.h \
    ../zoneanime.h \
    deplacement.h \
    fenetre.h \
    pause.h \
    scene.h \

RESOURCES += \
    ../ressources.qrc

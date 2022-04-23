#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Historique avec QStateMachine"
# exemple : QHistoryState
#           bonus 02
# Daniel Génon FEV 2022 Revin
# version : 1 : 16/02/2022 version QT 6.2
#-------------------------------------------------

QT += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += statemachine

TARGET = bonus02
TEMPLATE = app
CONFIG += c++11

SOURCES += \
    cible/histoperso.cpp \
    cible/transtouche.cpp \
    main.cpp \
    fenetre.cpp \
    ../objetimage.cpp \
    ../sequence.cpp \
    ../vue.cpp \
    ../zoneanime.cpp \
    cible/cible.cpp \
    cible/etatcouleur.cpp \
    scene.cpp

HEADERS += \
    ../objetimage.h \
    ../sequence.h \
    ../vue.h \
    ../zoneanime.h \
    cible/histoperso.h \
    cible/transtouche.h \
    fenetre.h \
    cible/cible.h \
    cible/etatcouleur.h \
    scene.h

RESOURCES += \
    ../ressources.qrc


#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Historique avec QStateMachine"
# exemple : QHistoryState
#           etape 03 : historiques en cascade
# Daniel Génon MAR 2022 Revin
# version : 1 : 10/03/2022 version QT 5.15.2 6.21 6.22
#-------------------------------------------------

QT += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += statemachine

TARGET = etape03
TEMPLATE = app
CONFIG += c++11

SOURCES += \
    main.cpp \
    ../objetimage.cpp \
    ../sequence.cpp \
    ../vue.cpp \
    ../zoneanime.cpp \
    fenetre.cpp \
    scene.cpp \
    groupecible/etatgroupe.cpp \
    groupecible/groupecible.cpp \
    groupecible/cible/cible.cpp \
    groupecible/cible/etatcouleur.cpp \
    groupecible/cible/transeventsouris.cpp

HEADERS += \
    ../objetimage.h \
    ../sequence.h \
    ../vue.h \
    ../zoneanime.h \
    fenetre.h \
    scene.h \
    groupecible/groupecible.h \
    groupecible/etatgroupe.h \
    groupecible/cible/cible.h \
    groupecible/cible/etatcouleur.h \
    groupecible/cible/transeventsouris.h

RESOURCES += \
    ../ressources.qrc

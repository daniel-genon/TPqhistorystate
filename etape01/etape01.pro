#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Historique avec QStateMachine"
# exemple : QHistoryState
#           etape 01 : mise en place du test
# Daniel Génon DEC 2021 Revin
# version : 1 : 5/12/2021 version QT 5.15.2 6.21 6.22
#-------------------------------------------------

QT += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += statemachine

TARGET = etape01
TEMPLATE = app
CONFIG += c++11

SOURCES += \
    ../main.cpp \
    ../objetimage.cpp \
    ../fenetre.cpp \
    ../sequence.cpp \
    ../vue.cpp \
    ../zoneanime.cpp \
    ../parametre.cpp \
    cible/cible.cpp \
    cible/etatcouleur.cpp \
    cible/evntperso.cpp \
    cible/transcouleur.cpp \
    declencheur/arretdch.cpp \
    declencheur/declencheur.cpp \
    declencheur/deplacedch.cpp \
    scene.cpp

HEADERS += \
    ../objetimage.h \
    ../fenetre.h \
    ../sequence.h \
    ../vue.h \
    ../zoneanime.h \
    ../parametre.h \
    cible/cible.h \
    cible/etatcouleur.h \
    cible/evntperso.h \
    cible/transcouleur.h \
    declencheur/arretdch.h \
    declencheur/declencheur.h \
    declencheur/deplacedch.h \
    scene.h

RESOURCES += \
    ../ressources.qrc

FORMS += \
    ../parametre.ui

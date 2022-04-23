#include "cible.h"
#include "etatcouleur.h"
#include "transtouche.h"
#include <QMessageBox>

Cible::Cible( qreal posx, qreal posy)
{
    setPos( posx, posy );
    InitImage(QString(":/motif/neutre.png"));
    setZValue(2);
    setFlag( ItemIsFocusable, true );
    setFocus();

    machine = new QStateMachine(this);

    groupecouleur = new QState(machine);

    EtatCouleur *Cbleue = new EtatCouleur( ":/motif/bleue.png", this, groupecouleur );
    EtatCouleur *Crouge = new EtatCouleur( ":/motif/rouge.png", this, groupecouleur );
    EtatCouleur *Cverte = new EtatCouleur( ":/motif/verte.png", this, groupecouleur );
    EtatCouleur *Cjaune = new EtatCouleur( ":/motif/jaune.png", this, groupecouleur );
    EtatCouleur *Cbciel = new EtatCouleur( ":/motif/bciel.png", this, groupecouleur );
    EtatCouleur *Cmauve = new EtatCouleur( ":/motif/mauve.png", this, groupecouleur );

    TransTouche *stopB = new TransTouche(this, QEvent::KeyPress, Qt::Key_5);
        Cbleue->addTransition(stopB);
        stopB->setTargetState(Crouge);
    TransTouche *stopR = new TransTouche(this, QEvent::KeyPress, Qt::Key_5);
        Crouge->addTransition(stopR);
        stopR->setTargetState(Cverte);
    TransTouche *stopV = new TransTouche(this, QEvent::KeyPress, Qt::Key_5);
        Cverte->addTransition(stopV);
        stopV->setTargetState(Cjaune);
    TransTouche *stopJ = new TransTouche(this, QEvent::KeyPress, Qt::Key_5);
        Cjaune->addTransition(stopJ);
        stopJ->setTargetState(Cbciel);
    TransTouche *stopC = new TransTouche(this, QEvent::KeyPress, Qt::Key_5);
        Cbciel->addTransition(stopC);
        stopC->setTargetState(Cmauve);
    TransTouche *stopM = new TransTouche(this, QEvent::KeyPress, Qt::Key_5);
        Cmauve->addTransition(stopM);
        stopM->setTargetState(Cbleue);

        historique01 = new HistoPerso(this, groupecouleur);
        historique01->setDefaultState(Cbleue);
        historique02 = new HistoPerso(this, groupecouleur);
        historique02->setDefaultState(Cbleue);

        TransTouche *his01 = new TransTouche(this, QEvent::KeyPress, Qt::Key_4);
            groupecouleur->addTransition(his01);
            his01->setTargetState(historique01);
        TransTouche *his02 = new TransTouche(this, QEvent::KeyPress, Qt::Key_6);
            groupecouleur->addTransition(his02);
            his02->setTargetState(historique02);

        groupecouleur->setInitialState(Cbleue);

    machine->setInitialState(groupecouleur);
    machine->start();
}
Cible::~Cible()
{
    if (machine) { delete machine; }
}
void Cible::MessagePassage(const QString &libinfo, const QString &libmess)
{
    QMessageBox::information(NULL,libinfo,libmess);
}
void Cible::MessageEntree()
{
    QMessageBox::information(NULL,"Qhistorique","Entrée par onEntry de l'état historique");
}
void Cible::MessageSortie()
{
    QMessageBox::information(NULL,"Qhistorique","Sortie par onExit de l'état historique");
}

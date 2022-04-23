#include "cible.h"

Cible::Cible( ObjetImage *vtemoin, qreal posx, qreal posy)
{
    temoin = vtemoin;
    temoin->setPos( posx, posy-120 );
    temoin->setZValue(3);
    indcouleur = 1;

    InitImage(QString(":/motif/cible.png"));
    setPos( posx+76, posy+40 );
    setZValue(5);

    machine = new QStateMachine(this);

    EtatCouleur *Cbleue = new EtatCouleur( ":/motif/bleue.png", temoin, machine);
    EtatCouleur *Crouge = new EtatCouleur( ":/motif/rouge.png", temoin, machine);
    EtatCouleur *Cverte = new EtatCouleur( ":/motif/verte.png", temoin, machine);
    EtatCouleur *Cjaune = new EtatCouleur( ":/motif/jaune.png", temoin, machine);

    TransCouleur *JauneVersBleue = new TransCouleur(1);
    Cjaune->addTransition(JauneVersBleue);
    JauneVersBleue->setTargetState(Cbleue);

    TransCouleur *BleueVersRouge = new TransCouleur(2);
    Cbleue->addTransition(BleueVersRouge);
    BleueVersRouge->setTargetState(Crouge);

    TransCouleur *RougeVersVerte = new TransCouleur(3);
    Crouge->addTransition(RougeVersVerte);
    RougeVersVerte->setTargetState(Cverte);

    TransCouleur *VerteVersJaune = new TransCouleur(4);
    Cverte->addTransition(VerteVersJaune);
    VerteVersJaune->setTargetState(Cjaune);


    machine->setInitialState(Cbleue);
    machine->start();
}
Cible::~Cible()
{
    if (machine) { delete machine; }
}
void Cible::Change()
{
    indcouleur++;
    if(indcouleur>4)indcouleur=1;
    machine->postEvent(new EvntPerso(indcouleur));
}

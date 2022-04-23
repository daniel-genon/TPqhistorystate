#include "cible.h"
#include <QHistoryState>

Cible::Cible( ObjetImage *vtemoin, qreal posx, qreal posy)
{
    temoin = vtemoin;
    temoin->setPos( posx, posy-120 );
    temoin->setZValue(3);

    InitImage(QString(":/motif/cible.png"));
    setPos( posx+76, posy+40 );
    setZValue(5);

    machine = new QStateMachine(this);

    groupecouleur = new QState(machine);

    EtatCouleur *Cbleue = new EtatCouleur( ":/motif/bleue.png", temoin, groupecouleur);
    EtatCouleur *Crouge = new EtatCouleur( ":/motif/rouge.png", temoin, groupecouleur);
    EtatCouleur *Cverte = new EtatCouleur( ":/motif/verte.png", temoin, groupecouleur);
    EtatCouleur *Cjaune = new EtatCouleur( ":/motif/jaune.png", temoin, groupecouleur);
    lstetat << Cbleue << Crouge << Cverte << Cjaune ;
    groupecouleur->setInitialState(Cbleue);

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

    lsttrans << JauneVersBleue << BleueVersRouge << RougeVersVerte << VerteVersJaune ;

    historique = new QHistoryState(groupecouleur);
    historique->setDefaultState(Cbleue);

    machine->setInitialState(groupecouleur);
    machine->start();
}
Cible::~Cible()
{
    if (machine) { delete machine; }
}
void Cible::InitHistorique(QToolButton *histo)
{
    groupecouleur->addTransition(histo, SIGNAL(clicked()), historique);
}
void Cible::Change()
{
    int  indcouleur=1;
    QSet<QAbstractState*> setdetat = machine->configuration();
    setdetat.remove(groupecouleur);
    if(!setdetat.isEmpty())
    {
        if(lstetat.contains((EtatCouleur*) *setdetat.begin() ))
        {
           QAbstractState* etatentete = *setdetat.begin();
           QList<QAbstractTransition*> lsttransition = ((QState*)etatentete)->transitions();
           if(lsttrans.contains((TransCouleur*)lsttransition.first()))
               indcouleur = ((TransCouleur*)lsttransition.first())->ValCouleur();
        }
    }
    machine->postEvent(new EvntPerso(indcouleur));
}

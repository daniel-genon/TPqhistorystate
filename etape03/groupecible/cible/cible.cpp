#include "cible.h"
#include "transeventsouris.h"
#include "etatcouleur.h"

Cible::Cible(qreal posx, qreal posy)
{
    historique      = nullptr;
    groupecouleur   = nullptr;
    setPos( posx, posy );
    InitImage(QString(":/motif/neutre.png"));
    setZValue(3);
    setFlag( ItemIsFocusable, true );
    setAcceptedMouseButtons( Qt::LeftButton );

    QStateMachine *machine = new QStateMachine(this);
    groupecouleur  = new QState(machine);

    EtatCouleur *e0 = new EtatCouleur( ":/motif/bleue.png", this, groupecouleur );
    EtatCouleur *e1 = new EtatCouleur( ":/motif/rouge.png", this, groupecouleur );
    EtatCouleur *e2 = new EtatCouleur( ":/motif/verte.png", this, groupecouleur );
    EtatCouleur *e3 = new EtatCouleur( ":/motif/jaune.png", this, groupecouleur );
    EtatCouleur *e4 = new EtatCouleur( ":/motif/bciel.png", this, groupecouleur );
    EtatCouleur *e5 = new EtatCouleur( ":/motif/mauve.png", this, groupecouleur );

    groupecouleur->setInitialState(e0);

    TransEventSouris *BvR = new TransEventSouris( this, QEvent::GraphicsSceneMousePress, e0 );
        BvR->setTargetState(e1);
    TransEventSouris *RvV = new TransEventSouris( this, QEvent::GraphicsSceneMousePress, e1 );
        RvV->setTargetState(e2);
    TransEventSouris *VvJ = new TransEventSouris( this, QEvent::GraphicsSceneMousePress, e2 );
        VvJ->setTargetState(e3);
    TransEventSouris *JvC = new TransEventSouris( this, QEvent::GraphicsSceneMousePress, e3 );
        JvC->setTargetState(e4);
    TransEventSouris *CvM = new TransEventSouris( this, QEvent::GraphicsSceneMousePress, e4 );
        CvM->setTargetState(e5);
    TransEventSouris *MvB = new TransEventSouris( this, QEvent::GraphicsSceneMousePress, e5 );
        MvB->setTargetState(e0);

    historique = new QHistoryState(groupecouleur);
    historique->setDefaultState(e0);

    machine->setInitialState(groupecouleur);
    machine->start();
}
Cible::~Cible()
{
    if(historique){delete historique;}
    if(groupecouleur){delete groupecouleur;}
}
void Cible::InitHistorique(QToolButton *histo )
{
    groupecouleur->addTransition( histo, SIGNAL(clicked()), historique );
}

#include "declencheur.h"
#include <QtCore/QPropertyAnimation>
#include <QFinalState>
#include <QSignalTransition>
#include "deplacedch.h"
#include "arretdch.h"
#include "scene.h"
#include <QMessageBox>

Declencheur::Declencheur( Cible *vcbl )
{
    animationdelobjet = 0;
    machine=0;
    pcible = vcbl;

    InitImage(QString(":/motif/declencheur.png"));
    setZValue(8);
    setFlags(QGraphicsItem::ItemIsFocusable);

    animationdelobjet = new QPropertyAnimation( this, "pos" );
    animationdelobjet->setDuration(2500);

    machine = new QStateMachine(this);
    DeplaceDch *avance = new DeplaceDch( this, machine);
    ArretDch   *arrete = new ArretDch( this, machine );
    QSignalTransition *reprend = new QSignalTransition( animationdelobjet, SIGNAL(finished()) );
        avance->addTransition(reprend);
        reprend->setTargetState(arrete);
        arrete->addTransition( arrete, SIGNAL( RePositionner()), avance );

    connect( animationdelobjet, SIGNAL(valueChanged(QVariant)), this, SLOT(EnDeplacement()));

    machine->setInitialState(avance);
}
Declencheur::~Declencheur()
{
    if(machine)
    {
        machine->stop();
        delete machine;
    }
    if(animationdelobjet) delete animationdelobjet;
}
void Declencheur::BougeToi(){ if(!machine->isRunning()) { machine->start(); }}
void Declencheur::Stop(){ animationdelobjet->stop(); machine->stop(); }
void Declencheur::Initialiser()
{
    hide();
    pntfin=QPointF( (scene()->width() - size().width()), 0.5*((scene()->height()) - size().height()) );
    pntdepart=QPointF( 0, 0.5*((scene()->height()) - size().height()) );
    setPos(pntdepart);
    show();
    pcible->setVisible(true);
}
void Declencheur::InitPtrVue( Vue *vpvue )
{
    pvue=vpvue;
    if (pvue==0) { QMessageBox::information(NULL,"info", "pas de scene"); }
}
bool Declencheur::TestCollision()
{
    QList<QGraphicsItem*> lstobjet = collidingItems(Qt::IntersectsItemBoundingRect);
    return (lstobjet.contains(pcible));
}
void Declencheur::EnDeplacement()
{
    if(pcible->isVisible())
    {
        if( TestCollision() )
        {
            pcible->Change();
            pcible->setVisible(false);
        }
    }
}
void Declencheur::MajMouvement()
{
    animationdelobjet->stop();
    animationdelobjet->setStartValue(pntdepart);
    animationdelobjet->setEndValue(pntfin);
    animationdelobjet->start();
}

#include "scene.h"
#include <QtWidgets/QApplication>
#include <QStateMachine>
#include <QFinalState>
#include <QEventTransition>
#include "../zoneanime.h"
#include "groupecible/etatgroupe.h"

Scene::Scene(int x, int y, int width, int height) : QGraphicsScene(x , y, width, height)
{
    ObjetImage *fondItem = new ObjetImage( QString(":/motif/fond1.png"));
    fondItem->setZValue(1);
    fondItem->setPos(0,0);
    addItem(fondItem);
}
Scene::~Scene()
{
}
void Scene::InitialiserScene(QToolButton *quitterletest, QLineEdit *linformation, QToolButton *bhisto)
{
    linformation->setText("Historiques en cascade");
    QStateMachine *machine =new QStateMachine(this);
    ZoneAnime *zoneanime = new ZoneAnime( this, machine );
    QFinalState *final = new QFinalState( machine );
    zoneanime->addTransition( quitterletest, SIGNAL(clicked()), final );
    connect( machine, SIGNAL(finished()), qApp, SLOT(quit()));
    EtatGroupe *groupeA = new EtatGroupe( QString(":/motif/fondgrpA.png"), 50,  60, this );
    EtatGroupe *groupeB = new EtatGroupe( QString(":/motif/fondgrpB.png"), 50, 320, this );
    EtatGroupe *groupeC = new EtatGroupe( QString(":/motif/fondgrpC.png"), 50, 580, this );
    groupeA->setParent(zoneanime);
    groupeB->setParent(zoneanime);
    groupeC->setParent(zoneanime);

    QEventTransition *okA = new QEventTransition( groupeA->NoGroupe(), QEvent::GraphicsSceneMousePress, zoneanime );
        okA->setTargetState(groupeA);
    QEventTransition *okB = new QEventTransition( groupeB->NoGroupe(), QEvent::GraphicsSceneMousePress, zoneanime );
        okB->setTargetState(groupeB);
    QEventTransition *okC = new QEventTransition( groupeC->NoGroupe(), QEvent::GraphicsSceneMousePress, zoneanime );
        okC->setTargetState(groupeC);

    QHistoryState *historique = new QHistoryState( zoneanime );
    historique->setDefaultState(groupeA);
    zoneanime->addTransition(bhisto, SIGNAL(clicked()), historique);

    zoneanime->setInitialState(groupeA);
    machine->setInitialState(zoneanime);
    machine->start();
}
void Scene::DemarrerScene()
{
}
void Scene::InitPtrVue(Vue *vptr)
{
    ptrvue = vptr;
}
Vue *Scene::pVue() const{ return ptrvue;}

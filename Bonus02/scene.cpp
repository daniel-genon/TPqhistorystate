#include "scene.h"
#include <QtWidgets/QApplication>
#include <QStateMachine>
#include <QFinalState>
#include "../zoneanime.h"

Scene::Scene(int x, int y, int width, int height) : QGraphicsScene(x , y, width, height)
{
    ObjetImage *fondItem = new ObjetImage( QString(":/motif/fond1.png"));
    fondItem->setZValue(1);
    fondItem->setPos(0,0);
    addItem(fondItem);

    cible = new Cible( 470, 355 );
    addItem(cible);
}
Scene::~Scene()
{
    delete cible;
}
void Scene::InitialiserScene(QToolButton *quitterlejeu, QLineEdit *linformation)
{
    linformation->setText("mise en place");
    QStateMachine *machine =new QStateMachine(this);
    ZoneAnime *zoneanime = new ZoneAnime( this, machine );
    QFinalState *final = new QFinalState( machine );
    zoneanime->addTransition( quitterlejeu, SIGNAL(clicked()), final );
    connect( machine, SIGNAL(finished()), qApp, SLOT(quit()));
    machine->setInitialState(zoneanime);
    machine->start();
}

void Scene::DemarrerScene()
{
    setFocusItem(cible, Qt::OtherFocusReason);
}
void Scene::InitPtrVue(Vue *vptr)
{
    ptrvue = vptr;
}
Vue *Scene::pVue() const{ return ptrvue;}

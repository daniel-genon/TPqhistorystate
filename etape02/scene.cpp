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

    ObjetImage *tmptemoin = new ObjetImage();
    addItem(tmptemoin);
    cible = new Cible( tmptemoin,  460, 350 );
    addItem(cible);

    declencheur = new Declencheur( cible );
    addItem(declencheur);
    declencheur->hide();
}
Scene::~Scene()
{
    delete declencheur;
    delete cible;
}
void Scene::InitialiserScene( QToolButton *quitterlejeu, QLineEdit *linformation, QToolButton *histo)
{
    linformation->setText("Étape 2 : simple état historique");
    cible->InitHistorique(histo);
    QStateMachine *machine =new QStateMachine(this);
    ZoneAnime *zoneanime = new ZoneAnime(this, machine );
    QFinalState *final = new QFinalState( machine );
    zoneanime->addTransition(quitterlejeu, SIGNAL(clicked()), final );
    connect(machine, SIGNAL(finished()), qApp, SLOT(quit()));
    machine->setInitialState(zoneanime);
    machine->start();
}
void Scene::DemarrerScene()
{
    setFocusItem(declencheur, Qt::OtherFocusReason);
    declencheur->Initialiser();
    declencheur->BougeToi();
}
void Scene::InitPtrVue(Vue *vptr)
{
    ptrvue = vptr;
    declencheur->InitPtrVue(vptr);
}
Vue *Scene::pVue() const{ return ptrvue;}

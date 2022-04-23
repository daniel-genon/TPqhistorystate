#include "scene.h"
#include <QtWidgets/QApplication>
#include <QStateMachine>
#include <QFinalState>
#include <QEventTransition>
#include <QHistoryState>
#include <QSignalTransition>
#include "../zoneanime.h"
#include "deplacement.h"
#include "pause.h"
#include <QPushButton>

Scene::Scene(int x, int y, int width, int height) : QGraphicsScene(x , y, width, height)
{
    resultat    = 0;
    ObjetImage *fondItem = new ObjetImage( QString(":/motif/fond1.png"));
        fondItem->setZValue(1);
        fondItem->setPos(0,0);
    addItem(fondItem);

    image   = new ObjetImage(QString(":/motif/declencheur.png"));
        image->setZValue(3);
        image->setPos(0,0);
    addItem(image);
}
Scene::~Scene()
{
    delete image;
}
void Scene::InitialiserScene(QToolButton *quitterletest, QLineEdit *linformation, QToolButton *bhisto)
{
    linformation->setText("Étape 04 : historique et interruption");

    QStateMachine *machine =new QStateMachine(this);
    ZoneAnime *zoneanime = new ZoneAnime( this, machine );
    QFinalState *final = new QFinalState( machine );
    zoneanime->addTransition( quitterletest, SIGNAL(clicked()), final );
        connect( machine, SIGNAL(finished()), qApp, SLOT(quit()));

    Deplacement *horz1 = new Deplacement( image, this,  250, zoneanime );
    Deplacement *horz2 = new Deplacement( image, this,  450, zoneanime );
    Deplacement *horz3 = new Deplacement( image, this,  600, zoneanime );
    Deplacement *horz4 = new Deplacement( image, this,  800, zoneanime );
    Deplacement *horz5 = new Deplacement( image, this, 1000, zoneanime );

        QSignalTransition *vers2 = new QSignalTransition( horz1->rtanimation(), SIGNAL(finished()), horz1 );
            vers2->setTargetState(horz2);
        QSignalTransition *vers3 = new QSignalTransition( horz2->rtanimation(), SIGNAL(finished()), horz2 );
            vers3->setTargetState(horz3);
        QSignalTransition *vers4 = new QSignalTransition( horz3->rtanimation(), SIGNAL(finished()), horz3 );
            vers4->setTargetState(horz4);
        QSignalTransition *vers5 = new QSignalTransition( horz4->rtanimation(), SIGNAL(finished()), horz4 );
            vers5->setTargetState(horz5);
        QSignalTransition *vers1 = new QSignalTransition( horz5->rtanimation(), SIGNAL(finished()), horz5 );
            vers1->setTargetState(horz1);

    QHistoryState *historique = new QHistoryState( zoneanime );

/**** Création d'une boite de dialogue d'interruption avec la classe Pause ***/

    Pause *etatpause = new Pause( (char*)&resultat, machine);
        etatpause->addTransition( historique );
    zoneanime->addTransition(bhisto, SIGNAL(clicked()), etatpause);

/**** Création d'une boite de dialogue d'interruption sans la classe Pause ***/

//    QState *etatpause = new QState(machine);
//            etatpause->addTransition( historique );

//        QMessageBox *raz = new QMessageBox();
//        raz->addButton( QString("continuer"), QMessageBox::AcceptRole );
//        QPushButton *sortir = raz->addButton( QString("quitter"), QMessageBox::NoRole );
//        raz->setText("une pause.");

//        zoneanime->addTransition(bhisto, SIGNAL(clicked()), etatpause);
//        connect( etatpause, SIGNAL(entered()), raz, SLOT(exec()) );
//        zoneanime->addTransition( sortir, SIGNAL(clicked()), final );

    zoneanime->setInitialState(horz1);
    machine->setInitialState(zoneanime);
    machine->start();
}
void Scene::Comptage(){    resultat++;}
void Scene::DemarrerScene(){}
void Scene::InitPtrVue(Vue *vptr){    ptrvue = vptr;}
Vue *Scene::pVue() const {   return ptrvue;}

#include "scene.h"
#include <QtWidgets/QApplication>
#include <QFinalState>
#include <QEventTransition>
#include <QHistoryState>
#include "../zoneanime.h"
#include <QMessageBox>

Scene::Scene(int x, int y, int width, int height) : QGraphicsScene(x , y, width, height)
{
    ObjetImage *fondItem = new ObjetImage( QString(":/motif/fond1.png"));
        fondItem->setZValue(1);
        fondItem->setPos(0,0);
        addItem(fondItem);
}
Scene::~Scene()
{
    if(!lstballe.empty())
    {
        for(int i=0;i<lstballe.size();++i)
        {
            delete lstballe[i].trdescente;
            delete lstballe[i].trmontee;
            delete lstballe[i].verslebas;
            delete lstballe[i].verslehaut;
            delete lstballe[i].etat;
            delete lstballe[i].balle;
            delete lstballe[i].descente;
            delete lstballe[i].montee;
        }
        lstballe.clear();
    }
}
void Scene::InitialiserScene(QToolButton *quitterletest, QLineEdit *linformation, QToolButton *bhisto)
{
    linformation->setText("Étape 05 : états parallèles, historique et animations");
    QStateMachine *machine =new QStateMachine(this);
    ZoneAnime *zoneanime = new ZoneAnime( this, machine );
    QFinalState *final = new QFinalState( machine );
    zoneanime->addTransition( quitterletest, SIGNAL(clicked()), final );
    connect( machine, SIGNAL(finished()), qApp, SLOT(quit()));

    QState *vertical = new QState(QState::ParallelStates, zoneanime);
        lstballe.append(CreerBalle(125,2000, vertical, true ));
        lstballe.append(CreerBalle(310,1000, vertical, true ));
        lstballe.append(CreerBalle(500,3000, vertical, true ));
        lstballe.append(CreerBalle(800,2500, vertical, true ));

/************************* DEBUT ZONE TEST DEEPHISTORY *****************/

// reprend à l'arrêt
    QHistoryState *historique = new QHistoryState(QHistoryState::DeepHistory, vertical );

// comportement insolite
//    QHistoryState *historique = new QHistoryState(QHistoryState::ShallowHistory, vertical );

// reprend à l'arrêt
//    QHistoryState *historique = new QHistoryState(QHistoryState::DeepHistory, zoneanime );


/************************* FIN ZONE TEST DEEPHISTORY *****************/

    QMessageBox *fenpause = new QMessageBox();
        fenpause->addButton(QMessageBox::Ok);
        fenpause->setText("c'est la Pause");
    QState *etatpause = new QState(machine);
        etatpause->addTransition( historique );
    zoneanime->addTransition(bhisto, SIGNAL(clicked()), etatpause);
    connect(etatpause, SIGNAL(entered()),fenpause, SLOT(exec()));

    zoneanime->setInitialState(vertical);
    machine->setInitialState(zoneanime);
    machine->start();
}

enrballe Scene::CreerBalle(int valdebx_ou_y, int duree, QState *parentballe, bool vert=true )
{
    enrballe rs;

    rs.balle   = new ObjetImage(QString(":/motif/declencheur.png"));
    rs.balle->setZValue(2);
    addItem(rs.balle);

    rs.descente = new QPropertyAnimation( rs.balle, "pos" );
        rs.descente->setDuration(duree);
    rs.montee = new QPropertyAnimation( rs.balle, "pos" );
        rs.montee->setDuration(duree);

    if(vert)
    {
        qreal max=height()-rs.balle->size().height();
        rs.balle->setPos(valdebx_ou_y,0);
        rs.descente->setEndValue(QPointF( valdebx_ou_y, max));
    }
    else
    {
        qreal max=width()-rs.balle->size().width();
        rs.balle->setPos(0,valdebx_ou_y);
        rs.descente->setEndValue(QPointF( max, valdebx_ou_y));
    }
    rs.descente->setStartValue(rs.balle->pos());
    rs.montee->setEndValue(rs.balle->pos());

    rs.etat        = new QState (QState::ExclusiveStates, parentballe);
    rs.verslebas   = new Deplacement( rs.descente, rs.etat );
    rs.verslehaut  = new Deplacement(rs.montee, rs.etat );
    rs.trdescente = new QSignalTransition( rs.descente, SIGNAL(finished()), rs.verslebas);
            rs.trdescente->setTargetState(rs.verslehaut);
    rs.trmontee    = new QSignalTransition( rs.montee, SIGNAL(finished()), rs.verslehaut);
            rs.trmontee->setTargetState(rs.verslebas);
    rs.etat->setInitialState(rs.verslebas);
    return rs;
}

void Scene::DemarrerScene()
{
}
void Scene::InitPtrVue(Vue *vptr)
{
    ptrvue = vptr;
}
Vue *Scene::pVue() const{ return ptrvue;}

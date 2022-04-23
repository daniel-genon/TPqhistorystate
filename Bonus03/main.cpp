/*
 Project created by QtCreator
 Support TP du livre "Historique avec QStateMachine"
           bonus 03
 exemple : "animation simple et machine à états"
 Daniel Génon AVRIL 2022 Revin
 version : 1 : 04/04/2022 version QT 5.15.2 6.21 6.22
*/

#include <QApplication>
#include <QStateMachine>
#include <QFinalState>
#include <QVBoxLayout>
#include <QWidget>
#include <QToolButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QHistoryState>
#include <QMessageBox>

class ObjetImage  : public QGraphicsObject
{
public:
    ObjetImage( QGraphicsItem* parent=0 ): QGraphicsObject(parent) { image=QPixmap(QString(":/declencheur.png")); }
protected:
    virtual QRectF boundingRect() const { return QRectF(QPointF(0, 0), image.size()); }
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) { painter->drawPixmap(0, 0, image);}
private:
    QPixmap         image;
};

class EtatAnimation : public QState
{
public:
    EtatAnimation( QGraphicsScene *vscene, qreal vposx, QState *parent = nullptr): QState(parent)
    {
        ObjetImage  *element = new ObjetImage;
        element->setZValue(5);
        element->setPos(vposx,0);
        vscene->addItem(element);
        animationdelobjet = new QPropertyAnimation( element, "pos" );
        animationdelobjet->setDuration(4000);
        animationdelobjet->setStartValue(QPointF( vposx, 0));
        animationdelobjet->setEndValue( QPointF( vposx, vscene->height()));
    }
    ~EtatAnimation() { delete animationdelobjet; };
protected:
    virtual void onEntry( QEvent *)    {       animationdelobjet->start();    }
//    virtual void onExit( QEvent *)    {        animationdelobjet->stop();    }
private:
    QPropertyAnimation *animationdelobjet;
};

class Fenetre : public QWidget
{
public:
    Fenetre(QWidget *parent=0) : QWidget(parent)
    {
//****   configuration fenetre
        setWindowTitle("test bonus 03");
        QGraphicsScene *scene = new QGraphicsScene(0, 0, 700, 700);
            scene->setBackgroundBrush(Qt::darkGray);

        QVBoxLayout *barrevert = new QVBoxLayout;
            QToolButton *quitter     = new QToolButton(this);
                quitter->setText("quitter");
                barrevert->addWidget(quitter);
            QToolButton *pauser = new QToolButton(this);
                pauser->setText("pause");
                barrevert->addWidget(pauser);
        QGridLayout *layoutdroite = new QGridLayout;
            layoutdroite->addLayout(barrevert,1,0);

        QVBoxLayout *layoutgraphique = new QVBoxLayout;
            QGraphicsView *fengraphique = new QGraphicsView(scene,this);
                layoutgraphique->addWidget(fengraphique);
        QGridLayout *toutLayout = new QGridLayout;
            toutLayout->addLayout(layoutgraphique, 0, 0);
            toutLayout->addLayout(layoutdroite, 0, 1);
        setLayout(toutLayout);

//****   configuration machine
        QStateMachine *machine = new QStateMachine(this);
        connect( machine, SIGNAL(finished()), qApp, SLOT(quit()));

        QFinalState *final = new QFinalState( machine );
        QState *zoneanime = new QState(machine);
            zoneanime->addTransition( quitter, SIGNAL(clicked()), final );

        EtatAnimation *descente1 = new EtatAnimation( scene, 100.0, zoneanime );
        EtatAnimation *descente2 = new EtatAnimation( scene, 200.0, zoneanime );
            descente1->addTransition(pauser, SIGNAL(clicked()), descente2);
            descente2->addTransition(pauser, SIGNAL(clicked()), descente1);

        zoneanime->setInitialState(descente1);
        machine->setInitialState(zoneanime);
        machine->start();
    }
};

int main(int argc, char **argv)
{
    QApplication testbonus03(argc, argv);
    Fenetre fenetre;
    fenetre.resize(800, 800);
    fenetre.show();
    return testbonus03.exec();
}


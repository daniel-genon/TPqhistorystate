/*-------------------------------------------------
 Project created by QtCreator
 Support TP du livre "Historique avec QStateMachine"
           bonus 04
 exemple : "animation simple et machine à états"
 Daniel Génon AVRIL 2022 Revin
 version : 1 : 06/04/2022 version QT 6.2
-------------------------------------------------*/

#include <QApplication>
#include <QStateMachine>
#include <QFinalState>
#include <QSignalTransition>
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
            QToolButton *changer = new QToolButton(this);
                changer->setText("démarrer/changer");
                barrevert->addWidget(changer);
        QGridLayout *layoutdroite = new QGridLayout;
            layoutdroite->addLayout(barrevert,1,0);

        QVBoxLayout *layoutgraphique = new QVBoxLayout;
            QGraphicsView *fengraphique = new QGraphicsView(scene,this);
                layoutgraphique->addWidget(fengraphique);
        QGridLayout *toutLayout = new QGridLayout;
            toutLayout->addLayout(layoutgraphique, 0, 0);
            toutLayout->addLayout(layoutdroite, 0, 1);
            setLayout(toutLayout);

//création animation à assigner

        ObjetImage  *element1 = new ObjetImage;
            element1->setPos(100,0);
        ObjetImage  *element2 = new ObjetImage;
            element2->setPos(200,0);
        QPropertyAnimation *animation1 = new QPropertyAnimation( element1, "pos" );
            animation1->setDuration(4000);
            animation1->setStartValue(QPointF( 100, 0));
        QPropertyAnimation *animation2 = new QPropertyAnimation( element2, "pos" );
            animation2->setDuration(3000);
            animation2->setStartValue(QPointF( 200, 0));

        scene->addItem(element1);
        scene->addItem(element2);

//****   configuration machine

        QStateMachine *machine = new QStateMachine(this);
        connect( machine, SIGNAL(finished()), qApp, SLOT(quit()));

        QFinalState *final = new QFinalState( machine );
        QState *zoneanime = new QState(machine);
        zoneanime->addTransition( quitter, SIGNAL(clicked()), final );

        QState *descente1 = new QState( zoneanime );
        QState *descente2 = new QState( zoneanime );
            descente1->assignProperty(animation1,"endValue", QPointF( 100, scene->height()));
            descente2->assignProperty(animation2,"endValue", QPointF( 200, scene->height()));

        QSignalTransition *tr1 = descente1->addTransition(changer, SIGNAL(clicked()), descente2);
        QSignalTransition *tr2 = descente2->addTransition(changer, SIGNAL(clicked()), descente1);
            tr1->addAnimation(animation1);
            tr2->addAnimation(animation2);

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


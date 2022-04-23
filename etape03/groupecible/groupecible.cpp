#include "groupecible.h"

GroupeCible::GroupeCible(const QString &nomfichier, qreal vx, qreal vy, QGraphicsScene *vscene )
{
    pscene = vscene;
    lstcible.clear();

    InitImage(nomfichier);
    setZValue(6);
    setPos( vx, vy );
    pscene->addItem(this);
    setFlag( ItemIsFocusable, true );
    setAcceptedMouseButtons( Qt::LeftButton );

    fond = new ObjetImage(":/motif/fondgrp.png");
    fond->setZValue(5);
    fond->setPos(vx,vy);
    pscene->addItem(fond);

    InitCible(":/general/pause1.png", vx+230, vy+15 );
    InitCible(":/general/pause2.png", vx+480, vy+15 );
    InitCible(":/general/pause3.png", vx+730, vy+15 );
    InsererBoutonHistorique( vx+40, vy+80 );
}
GroupeCible::~GroupeCible()
{
    if(!lstcible.empty())
    {
        for(int i=0;i<lstcible.size();++i) { delete lstcible[i]; }
        lstcible.clear();
    }
}
void GroupeCible::InitCible( const QString &nomfichier, qreal vx, qreal vy )
{
    ObjetImage *imagetmp = new ObjetImage( nomfichier );
    imagetmp->setPos( vx, vy );
    imagetmp->setZValue(4);
    pscene->addItem(imagetmp);
    Cible *tmpcible = new Cible( vx, vy );
    pscene->addItem(tmpcible);
    lstcible.append(tmpcible);
}
ObjetImage *GroupeCible::NoFond()
{
    return fond;
}
void GroupeCible::InsererBoutonHistorique( qreal vx, qreal vy )
{
    QToolButton *btnhisto = new QToolButton;
    QIcon iconetmp;
        iconetmp.addFile(":/general/ouvert.png",QSize(40,40),QIcon::Normal,QIcon::Off );
        iconetmp.addFile(":/general/ferme.png",QSize(40,40),QIcon::Normal,QIcon::On );
    btnhisto->setCheckable(true);
    btnhisto->setIcon(iconetmp);
    btnhisto->setIconSize( QSize (80,80));
    btnhisto->setToolTip("restaure/historise le groupe");
    BoutonDansScene = pscene->addWidget(btnhisto);
    BoutonDansScene->setPos( vx, vy );
    BoutonDansScene->setZValue(3);
    for(int i=0;i<lstcible.size();++i) { lstcible[i]->InitHistorique(btnhisto); }
}

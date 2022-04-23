#include "etatgroupe.h"

EtatGroupe::EtatGroupe(const QString &nomfichier, qreal vx, qreal vy , QGraphicsScene *pscene )
{
    groupecible = new GroupeCible( nomfichier, vx, vy, pscene );
    pfond = groupecible->NoFond();
}
EtatGroupe::~EtatGroupe()
{
}
void EtatGroupe::onEntry(QEvent *)
{
    pfond->setZValue(2);
}
void EtatGroupe::onExit(QEvent *)
{
    pfond->setZValue(5);
}
QObject *EtatGroupe::NoGroupe()
{
    return static_cast<QObject*>(groupecible);
}

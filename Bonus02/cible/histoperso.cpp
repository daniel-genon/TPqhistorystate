#include "histoperso.h"
#include "cible.h"

HistoPerso::HistoPerso(QObject *vcible, QState *vparent)  : QHistoryState(vparent)
{
    pcible = vcible;
}
void HistoPerso::onEntry(QEvent*)
{
    static_cast<Cible*>(pcible)->MessageEntree();
}
void HistoPerso::onExit(QEvent*)
{
    static_cast<Cible*>(pcible)->MessageSortie();
}

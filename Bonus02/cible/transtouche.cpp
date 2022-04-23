#include "transtouche.h"

TransTouche::TransTouche(Cible *vcible, QEvent::Type t, int k) : QKeyEventTransition(vcible, t, k)
{
    cible=vcible;
}
bool TransTouche::eventTest(QEvent *evt)
{
    if (!QKeyEventTransition::eventTest(evt)) return false;
    cible->MessagePassage(QString("eventTest"),QString("test évènement transtouche"));
    return true;
}
void TransTouche::onTransition(QEvent *)
{
    cible->MessagePassage(QString("ontransition"),QString("transition transtouche"));
}

#include "transeventsouris.h"

TransEventSouris::TransEventSouris(QObject *dobject, QEvent::Type dtype, QState *source)
    : QEventTransition( dobject, dtype, source )
{
}
bool TransEventSouris::eventTest( QEvent *evt)
{
    if (!QEventTransition::eventTest(evt)) return false;
    return true;
}

#include "transcouleur.h"

TransCouleur::TransCouleur( int vcoul){    evtcouleur = vcoul;}
bool TransCouleur::eventTest(QEvent *evt )
{
    if(evt->type() == QEvent::Type( QEvent::User ))
    {
        return ( evtcouleur == ((EvntPerso*)evt)->ValCouleur());
    }
    return false;
}
void TransCouleur::onTransition(QEvent *){}

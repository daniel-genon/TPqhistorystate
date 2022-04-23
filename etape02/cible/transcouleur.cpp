#include "transcouleur.h"

TransCouleur::TransCouleur( int vcoul)
{
    evtcouleur = vcoul;
}
bool TransCouleur::eventTest(QEvent *evt )
{
    if(evt->type() != QEvent::Type( QEvent::User+1 )) return false;
    return ( evtcouleur == ((EvntPerso*)evt)->ValCouleur());
}
void TransCouleur::onTransition(QEvent *)
{

}
int TransCouleur::ValCouleur() const
{
    return evtcouleur;
}

#include "transcouleur.h"

TransCouleur::TransCouleur(Cible *vcible , QEvent::Type t) : QEventTransition(vcible, t )
{
//    setEventSource(vcible);
//    setEventType(QEvent::GraphicsSceneMousePress);
    cible = vcible;
}
bool TransCouleur::evenTest( QEvent *evt)
{
    if(!QEventTransition::eventTest(evt))
        return false;
return true;
//    QGraphicsScene  *pscene = cible->scene();
//    QGraphicsItem *tutu = pscene->mouseGrabberItem();
//    return tutu== (QGraphicsItem *)cible;
}

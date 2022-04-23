#include "evntperso.h"

EvntPerso::EvntPerso(int vcoul ) : QEvent(QEvent::Type(QEvent::User))
{
    couleur = vcoul;
}
int EvntPerso::ValCouleur()
{
    return couleur;
}

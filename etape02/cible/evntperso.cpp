#include "evntperso.h"

EvntPerso::EvntPerso() : QEvent(QEvent::Type(QEvent::User+1)) {}
EvntPerso::EvntPerso(int vcoul ) : QEvent(QEvent::Type(QEvent::User+1))
{
    couleur = vcoul;
}
void EvntPerso::Couleur(int vcoul)
{
    couleur = vcoul;
}
int EvntPerso::ValCouleur()
{
    return couleur;
}

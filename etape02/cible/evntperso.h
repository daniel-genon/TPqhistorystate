#ifndef EVNTPERSO_H
#define EVNTPERSO_H

#include <QEvent>

class EvntPerso : public QEvent
{
public:
    EvntPerso();
    EvntPerso(int vcoul);
    void Couleur(int vcoul);
    int ValCouleur();


private:
    int couleur;
};

#endif // EVNTPERSO_H

#ifndef EVNTPERSO_H
#define EVNTPERSO_H

#include <QEvent>

class EvntPerso : public QEvent
{
public:
    EvntPerso(int vcoul);
    int ValCouleur();
private:
    int couleur;
};

#endif // EVNTPERSO_H

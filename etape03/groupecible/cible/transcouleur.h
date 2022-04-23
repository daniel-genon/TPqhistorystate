#ifndef TRANSCOULEUR_H
#define TRANSCOULEUR_H

#include <QEventTransition>
#include "cible.h"

class TransCouleur : public QEventTransition
{
     Q_OBJECT
public:
    TransCouleur(Cible *vcible, QEvent::Type t );

protected:
    virtual bool evenTest( QEvent *evt);

private:
    Cible   *cible;

};

#endif // TRANSCOULEUR_H

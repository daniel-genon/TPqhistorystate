#ifndef TRANSCOULEUR_H
#define TRANSCOULEUR_H

#include <QAbstractTransition>
#include "evntperso.h"

class TransCouleur : public QAbstractTransition
{
    Q_OBJECT
public:
    TransCouleur(int vcoul );

protected:
    virtual bool eventTest( QEvent *evt );
    virtual void onTransition(QEvent *);

private:
    int evtcouleur;

};

#endif // TRANSCOULEUR_H

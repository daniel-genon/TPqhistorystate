#ifndef TRANSTOUCHE_H
#define TRANSTOUCHE_H

#include <QKeyEventTransition>
#include "cible.h"

class TransTouche : public QKeyEventTransition
{
    Q_OBJECT
public:
    TransTouche(Cible *vcible, QEvent::Type t, int k);
protected:
    virtual bool eventTest(QEvent *evt);
    virtual void onTransition(QEvent *);
private:
    Cible *cible;
};

#endif // TRANSTOUCHE_H

#ifndef DEPLACEDCH_H
#define DEPLACEDCH_H

#include "declencheur.h"
class DeplaceDch : public QState
{
    Q_OBJECT
public:
    DeplaceDch(Declencheur *vdcl, QState *vparent=0);
    ~DeplaceDch();

protected:
    virtual void onEntry(QEvent *);
private:
    Declencheur * declencheur;
};

#endif // DEPLACEDCH_H

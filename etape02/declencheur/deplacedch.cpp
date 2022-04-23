#include "deplacedch.h"

DeplaceDch::DeplaceDch(Declencheur *vdcl, QState *vparent ) : QState(vparent)
{
    declencheur = vdcl;
}
DeplaceDch::~DeplaceDch(){}
void DeplaceDch::onEntry(QEvent *)
{
    declencheur->MajMouvement();
}

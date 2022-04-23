#include "arretdch.h"
ArretDch::ArretDch(Declencheur *vdcl, QState *vparent) : QState(vparent)
{
    declencheur = vdcl;
}
ArretDch::~ArretDch(){}
void ArretDch::onEntry(QEvent *)
{
    declencheur->Initialiser();
    emit RePositionner();
}

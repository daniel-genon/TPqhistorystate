#include "deplacement.h"

Deplacement::Deplacement( QPropertyAnimation *vanime, QState *vparent ) : QState(vparent)
{
    animation = vanime;
}
void Deplacement::onEntry(QEvent *)
{
    if(animation->state()==QAbstractAnimation::Paused)
        animation->resume();
    else
        animation->start();
}
void Deplacement::onExit(QEvent *)
{
    if(animation->state()==QAbstractAnimation::Running)
        animation->pause();
    else
        animation->stop();
}

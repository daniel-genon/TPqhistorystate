#include "deplacement.h"

Deplacement::Deplacement(ObjetImage *vimage, Scene *vscene, qreal vposx,  QState *vparent ) : QState(vparent)
{
    pscene = vscene;
    ptdebut = QPointF( vposx, - vimage->size().height());
    animationdelobjet = new QPropertyAnimation( vimage, "pos" );
    animationdelobjet->setDuration(900);
    animationdelobjet->setStartValue(ptdebut);
    animationdelobjet->setEndValue( QPointF( vposx, vscene->height() + vimage->size().height()));
}
Deplacement::~Deplacement()
{
    delete animationdelobjet;
}
void Deplacement::onEntry(QEvent *)
{
    if(animationdelobjet->state()==QAbstractAnimation::Paused)
        animationdelobjet->resume();
    else
        animationdelobjet->start();
}
void Deplacement::onExit(QEvent *)
{
    if(animationdelobjet->state()==QAbstractAnimation::Running)
        animationdelobjet->pause();
    else
    {
        pscene->Comptage();
        animationdelobjet->stop();
    }
}
QVariantAnimation *Deplacement::rtanimation() const
{
    return animationdelobjet;
}

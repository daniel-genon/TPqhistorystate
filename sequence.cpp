#include "sequence.h"
Sequence::Sequence(Scene *vscene, QState *parent) : QState(parent)
{
    scene = vscene;
}
void Sequence::onEntry(QEvent *)
{
    scene->DemarrerScene();
}

#include "zoneanime.h"
#include "sequence.h"
ZoneAnime::ZoneAnime(Scene *vscene, QState *vparent): QState(vparent)
{
    scene = vscene;
    machine = 0;
}
ZoneAnime::~ZoneAnime()
{
    if (machine)
    {
        delete machine;
    }
}
void ZoneAnime::onEntry(QEvent *)
{
    if (machine)
    {
        machine->stop();
        delete machine;
    }
    machine = new QStateMachine;
    Sequence *sequence = new Sequence(scene, machine);
    machine->setInitialState(sequence);
    machine->start();
}

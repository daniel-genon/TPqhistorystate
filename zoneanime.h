#ifndef ZONEANIME_H
#define ZONEANIME_H

#include <QState>
#include <QStateMachine>
#include "scene.h"
class ZoneAnime : public QState
{
   Q_OBJECT
public:
    ZoneAnime(Scene *vscene, QState *vparent = 0);
    ~ZoneAnime();
protected:
   virtual void onEntry(QEvent *);
private :
    Scene *scene;
    QStateMachine *machine;
};

#endif // ZONEANIME_H

#ifndef PLATEAU_H
#define PLATEAU_H

#include "zoneanime.h"
class Sequence : public QState
{
public:
    Sequence(Scene *vscene, QState *parent = 0);
protected:
    virtual void onEntry(QEvent *);
private :
    Scene   *scene;
};

#endif // PLATEAU_H

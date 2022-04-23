#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <QState>
#include "../objetimage.h"
#include <QPropertyAnimation>
#include "scene.h"

class Deplacement : public QState
{
    Q_OBJECT
public:
    Deplacement(ObjetImage *vimage, Scene *vscene, qreal vposx, QState *vparent );
    ~Deplacement();
    QVariantAnimation   *rtanimation() const;

protected:
    virtual void onEntry(QEvent *);
    virtual void onExit(QEvent *);

private:
    QPointF             ptdebut;
    QVariantAnimation   *animationdelobjet;
    Scene               *pscene;
};

#endif // DEPLACEMENT_H

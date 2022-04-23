#ifndef SCENE_H
#define SCENE_H

#include <QStateMachine>
#include <QSignalTransition>
#include <QToolButton>
#include <QLineEdit>
#include <QPropertyAnimation>
#include "../vue.h"
#include "../objetimage.h"
#include "deplacement.h"

struct enrballe
{
    ObjetImage *balle               = nullptr;
    QState *etat                    = nullptr;
    QPropertyAnimation *descente    = nullptr;
    QPropertyAnimation *montee      = nullptr;
    QSignalTransition *trdescente   = nullptr;
    QSignalTransition *trmontee     = nullptr;
    Deplacement *verslebas          = nullptr;
    Deplacement *verslehaut         = nullptr;
};

class Scene : public QGraphicsScene
{
Q_OBJECT
public:
    Scene(int x, int y, int width, int height);
    ~Scene();
    void InitialiserScene( QToolButton *quitterletest, QLineEdit *linformation, QToolButton *bhisto);
    void DemarrerScene();
    void InitPtrVue(Vue *vptr);
    Vue *pVue() const;

private:
    Vue     *ptrvue;
    QList<enrballe>  lstballe;
//    void CreerBalle(int posx, int duree,
//                     ObjetImage *&balle,
//                     QPropertyAnimation *&descenteballe, QPropertyAnimation *&remonteeballe );
    enrballe CreerBalle(int valdebx_ou_y, int duree, QState *parentballe , bool horz);
//    void CreerEtat(enrballe &enr, QState *parentballe );


//    void CreerEtat( QState *etatballe,
//                    QPropertyAnimation *descenteballe, QPropertyAnimation *remonteeballe,
//                    QSignalTransition *&trd,QSignalTransition *&trm,
//                    Deplacement *&VD, Deplacement *&VR);

//    int haut, large;

};

#endif // SCENE_H

#ifndef SCENE_H
#define SCENE_H

#include <QToolButton>
#include <QLineEdit>
#include "../vue.h"
#include "declencheur/declencheur.h"
#include "cible/cible.h"
class Scene : public QGraphicsScene
{
Q_OBJECT
public:
    Scene(int x, int y, int width, int height);
    ~Scene();
    void InitialiserScene( QToolButton *quitterlejeu, QLineEdit *linformation );
    void DemarrerScene();
    void InitPtrVue(Vue *vptr);
    Vue *pVue() const;

private:

    Declencheur *declencheur;
    Cible       *cible;
    Vue         *ptrvue;

};

#endif // SCENE_H

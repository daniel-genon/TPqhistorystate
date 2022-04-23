#ifndef SCENE_H
#define SCENE_H

#include <QToolButton>
#include <QLineEdit>
#include "../vue.h"
#include <../objetimage.h>

class Scene : public QGraphicsScene
{
Q_OBJECT
public:
    Scene(int x, int y, int width, int height);
    ~Scene();
    void InitialiserScene( QToolButton *quitterletest, QLineEdit *linformation, QToolButton *bhisto);
    void Comptage();
    void DemarrerScene();
    void InitPtrVue(Vue *vptr);
    Vue *pVue() const;

private:
    ObjetImage  *image;
    Vue         *ptrvue;
    uint        resultat;
};

#endif // SCENE_H

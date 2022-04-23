#ifndef DECLENCHEUR_H
#define DECLENCHEUR_H

#include <QVariantAnimation>
#include "../../vue.h"
#include "../objetimage.h"
#include "../cible/cible.h"

class Declencheur : public ObjetImage
{
    Q_OBJECT
public:
    Declencheur(Cible *vcbl);
    ~Declencheur();

    void Initialiser();
    void MajMouvement();
    void InitPtrVue(Vue *vpvue );
    void BougeToi();
    void Stop();

protected:
    QVariantAnimation *animationdelobjet;
    QStateMachine *machine;

private slots:
    void EnDeplacement();

private:
    Vue     *pvue;
    Cible   *pcible;
    QPointF pntfin;
    QPointF pntdepart;

    bool TestCollision();
};

#endif // DECLENCHEUR_H

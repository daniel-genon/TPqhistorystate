#ifndef CIBLE_H
#define CIBLE_H

#include <QStateMachine>
#include "../objetimage.h"
#include "etatcouleur.h"
#include "transcouleur.h"

class Cible : public ObjetImage
{
    Q_OBJECT
public:
    Cible(ObjetImage *vtemoin, qreal posx, qreal posy);
    ~Cible();

    void Change();

protected:
    QStateMachine *machine;

private:
    ObjetImage  *temoin;
    int         indcouleur;

};

#endif // CIBLE_H

#ifndef CIBLE_H
#define CIBLE_H

#include <QStateMachine>
#include "../objetimage.h"
#include "etatcouleur.h"
#include "transcouleur.h"
#include <QHistoryState>
#include <QToolButton>

class Cible : public ObjetImage
{
    Q_OBJECT
public:
    Cible(ObjetImage *vtemoin, qreal posx, qreal posy);
    ~Cible();

    void Change();
    void InitHistorique(QToolButton *histo);

protected:
    QStateMachine *machine;

private:
    ObjetImage      *temoin;
    QState          *groupecouleur;
    QHistoryState   *historique;

    QList<EtatCouleur*>  lstetat;
    QList<TransCouleur*> lsttrans;

};

#endif // CIBLE_H

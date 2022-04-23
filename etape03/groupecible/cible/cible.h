#ifndef CIBLE_H
#define CIBLE_H

#include "../objetimage.h"
#include <QStateMachine>
#include <QHistoryState>
#include <QToolButton>

class Cible : public ObjetImage
{
    Q_OBJECT
public:
    Cible( qreal posx, qreal posy );
    ~Cible();
    void InitHistorique(QToolButton *histo );

private:
    QHistoryState   *historique;
    QState          *groupecouleur;

};

typedef QList<Cible*> LCible;

#endif // CIBLE_H

#ifndef CIBLE_H
#define CIBLE_H

#include "../objetimage.h"
#include <QStateMachine>
#include <QHistoryState>
#include <QToolButton>
#include "histoperso.h"


class Cible : public ObjetImage
{
    Q_OBJECT
public:
    Cible( qreal posx, qreal posy);
    ~Cible();

    void MessagePassage(const QString &libinfo, const QString &libmess );
    void MessageEntree();
    void MessageSortie();

protected:
    QStateMachine   *machine;

private:
    QState      *groupecouleur;
    HistoPerso  *historique01, *historique02;

};

#endif // CIBLE_H

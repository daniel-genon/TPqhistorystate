#ifndef ETATGROUPE_H
#define ETATGROUPE_H

#include "groupecible/groupecible.h"

class EtatGroupe : public QState
{
    Q_OBJECT
public:
    EtatGroupe( const QString &nomfichier, qreal vx, qreal vy );
    ~EtatGroupe();

private:
    GroupeCible *groupecible;
};

#endif // ETATGROUPE_H

#ifndef ETATGROUPE_H
#define ETATGROUPE_H

#include "groupecible.h"

class EtatGroupe : public QState
{
    Q_OBJECT
public:
    EtatGroupe(const QString &nomfichier, qreal vx, qreal vy, QGraphicsScene *pscene );
    ~EtatGroupe();

    QObject *NoGroupe();

protected:
    virtual void onEntry(QEvent *);
    virtual void onExit(QEvent *);

private:
    GroupeCible *groupecible;
    ObjetImage  *pfond;
};

#endif // ETATGROUPE_H

#ifndef ETATCOULEUR_H
#define ETATCOULEUR_H

#include <QState>
#include "cible.h"

class EtatCouleur : public QState
{
    Q_OBJECT

public:
    EtatCouleur( const QString &ficoul, Cible *vtem, QState *vparent = 0 );

protected:
    virtual void onEntry(QEvent *);

private:
    QString     couleur;
    Cible       *temoin;

};

#endif // ETATCOULEUR_H

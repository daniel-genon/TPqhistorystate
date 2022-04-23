#ifndef ETATCOULEUR_H
#define ETATCOULEUR_H

#include <QState>
#include "../objetimage.h"

class EtatCouleur : public QState
{
    Q_OBJECT

public:
    EtatCouleur( const QString &ficoul, ObjetImage *vtem, QState *vparent = 0 );
//    int ValCouleur() const;

protected:
    virtual void onEntry(QEvent *);

private:
    QString     couleur;
    ObjetImage  *temoin;

};

#endif // ETATCOULEUR_H

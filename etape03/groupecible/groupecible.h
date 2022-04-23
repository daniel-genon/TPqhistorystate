#ifndef GROUPECIBLE_H
#define GROUPECIBLE_H

#include "cible/cible.h"
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>

class GroupeCible : public ObjetImage
{
    Q_OBJECT
public:
    GroupeCible(const QString &nomfichier, qreal vx, qreal vy, QGraphicsScene *vscene );
    ~GroupeCible();

    ObjetImage *NoFond();

private:
    ObjetImage *fond;
    LCible  lstcible;
    QGraphicsScene *pscene;
    QGraphicsProxyWidget *BoutonDansScene;

    void InitCible(const QString &nomfichier, qreal vx, qreal vy);
    void InsererBoutonHistorique(qreal vx, qreal vy);

};



#endif // GROUPECIBLE_H

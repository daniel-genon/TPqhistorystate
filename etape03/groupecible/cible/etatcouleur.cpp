#include "etatcouleur.h"

EtatCouleur::EtatCouleur( const QString &ficoul, Cible *vtem, QState *vparent ) : QState(vparent)
{
    temoin  = vtem;
    couleur = ficoul;
}
void EtatCouleur::onEntry(QEvent *)
{
    temoin->hide();
    temoin->ChangeImage(couleur);
    temoin->show();
    temoin->setFlag( QGraphicsItem::ItemIsFocusable, true );
}

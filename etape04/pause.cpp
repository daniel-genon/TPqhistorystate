#include "pause.h"
Pause::Pause(char *vresultat, QState *vparent) : QState(vparent)
{
    presultat   = vresultat;
    phrtmp      = QString("Le nombre de balles tombées est de : %1");
    raz.addButton( QString("supprimer"), QMessageBox::AcceptRole );
    raz.addButton( QString("conserver"), QMessageBox::NoRole );
    raz.setWindowTitle( QString("Résultat") );
}
void Pause::onEntry(QEvent *)
{
    raz.setText(phrtmp.arg((uint) *presultat));
    if( raz.exec() == QMessageBox::AcceptRole) {  *presultat = 0; }
}

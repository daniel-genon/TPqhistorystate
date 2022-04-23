#ifndef FENETRE_H
#define FENETRE_H

#include <QtWidgets>
#include "scene.h"

class Fenetre : public QWidget
{
    Q_OBJECT
public:
    Fenetre(QWidget *parent = 0);
    ~Fenetre();

private :
    QString phrtmp;
    Vue     *ptrvue;
    Scene   *pscene;
    QToolButton     *quitter, *btnhisto;
    QLineEdit       *ligneinfo1;
    QVBoxLayout     *layoutgraphique;
    QGridLayout     *layinfo;
    QGridLayout     *layoutdroite;
    QGridLayout     *toutLayout;
    void    CreerLeMenu();
    void    TitreDeLaFenetre();
    void    ConfigurationFenetre();
    void    CreerUnBouton(QToolButton *qbt, const QString &icone, const QString &msg,int tailleicone=20);
    QVBoxLayout *BarreBouton();

};

#endif // FENETRE_H

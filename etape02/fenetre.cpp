#include "fenetre.h"
#include "../parametre.h"

Fenetre::Fenetre(QWidget *parent) : QWidget(parent)
{
    ConfigurationFenetre();
    resize(1178, 907 );
    TitreDeLaFenetre();
    pscene = new Scene(0, 0, 1100, 850);
    ptrvue = new Vue(pscene,this);
    CreerLeMenu();
    pscene->InitPtrVue(ptrvue);
    pscene->InitialiserScene( quitter, ligneinfo1, btnhisto);
}
Fenetre::~Fenetre()
{
    delete btnhisto;
    delete layoutdroite;
    delete layoutgraphique;
    delete layinfo;
    delete toutLayout;
    delete pscene;
    delete ptrvue;
}
bool Fenetre::Configuration()
{
    bool okvaleur=false;
    Parametre *dlg = new Parametre;
    dlg->setModal(true);
// charger les valeurs actuelles dans la boite dlg->IniBoite();
    if(dlg->exec()==QDialog::Accepted)
    {
        okvaleur=true;//mise à jour du fichier parametre
    }
    delete dlg;
    return okvaleur;
}
void Fenetre::ConfigurationFenetre()
{
    QColor valfond(0x3c,0x64,0x83);
    QPalette fond;
    fond.setColor( QPalette::Active,   QPalette::Window,valfond);
    fond.setColor( QPalette::Inactive, QPalette::Window,valfond);
    QWidget::setPalette(fond);
}
void Fenetre::TitreDeLaFenetre()
{
    phrtmp.clear();
    phrtmp.append("Test QHistoryState");
    setWindowTitle(phrtmp);
}
void Fenetre::CreerUnBouton( QToolButton *qbt, const QString &icone, const QString &msg, int tailleicone)
{
    QString ptmp(icone);
    if(ptmp.isEmpty()){ ptmp = ":/icone/apropos.png";}
    qbt->setIcon( QIcon(QPixmap(ptmp)));
    qbt->setIconSize( QSize (tailleicone,tailleicone));
    qbt->setToolTip(msg);
}
QVBoxLayout* Fenetre::BarreBouton()
{
    int htico = 40;
    QVBoxLayout *barrevert = new QVBoxLayout;
    quitter = new QToolButton;
    CreerUnBouton( quitter, ":/general/quitter.png", "quitter le jeu", htico);
      barrevert->addWidget(quitter);
    configuration = new QToolButton;
    CreerUnBouton( configuration, ":/general/configuration.png","paramètrage du jeu", htico);
      barrevert->addWidget(configuration);
    connect(configuration, SIGNAL(clicked()), this, SLOT(Configuration()));
    return barrevert;
}
QVBoxLayout* Fenetre::BarreBoutonHisto()
{
    int htico = 35;
    QVBoxLayout *barrevert = new QVBoxLayout;
    btnhisto = new QToolButton;
    CreerUnBouton( btnhisto, ":/general/ouvert.png", "pause cible 1", htico);
      barrevert->addWidget(btnhisto);
    return barrevert;
}
void Fenetre::CreerLeMenu()
{
    layoutgraphique = new QVBoxLayout;
    layoutgraphique->addWidget(ptrvue);
    layoutdroite = new QGridLayout;
    layoutdroite->addLayout(BarreBouton(),1,0);
    layoutdroite->addLayout(BarreBoutonHisto(),2,0);
    layinfo = new QGridLayout;
    ligneinfo1 = new QLineEdit( QString("Ligne d'information"));
    layinfo->addWidget(ligneinfo1,0,0, Qt::AlignVCenter);
    toutLayout = new QGridLayout;
    toutLayout->addLayout(layoutgraphique, 0, 0);
    toutLayout->addLayout(layoutdroite, 0, 1);
    toutLayout->addLayout(layinfo, 1, 0);
    setLayout(toutLayout);
}

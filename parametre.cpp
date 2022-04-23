#include "parametre.h"
#include "ui_parametre.h"

Parametre::Parametre(QWidget *parent): QDialog(parent), ui(new Ui::Parametre)
{ui->setupUi(this);}
Parametre::~Parametre(){delete ui;}

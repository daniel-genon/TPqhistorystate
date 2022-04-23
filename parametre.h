#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <QDialog>
namespace Ui {class Parametre;}
class Parametre : public QDialog
{
    Q_OBJECT
public:
    explicit Parametre(QWidget *parent = 0);
    ~Parametre();
private:
    Ui::Parametre *ui;
};

#endif // PARAMETRE_H

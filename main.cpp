#include "fenetre.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(ressources);
    QApplication a(argc, argv);
    Fenetre f;
    f.show();

    return a.exec();
}

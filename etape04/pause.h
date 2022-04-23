#ifndef PAUSE_H
#define PAUSE_H

#include <QState>
#include <QMessageBox>

class Pause : public QState
{
    Q_OBJECT
public:
    Pause(char *vresultat, QState *vparent );

protected:
    virtual void onEntry(QEvent *);

private:
    QString     phrtmp;
    QMessageBox raz;
    char        *presultat;

};

#endif // PAUSE_H

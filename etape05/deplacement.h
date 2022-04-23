#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <QState>
#include <QPropertyAnimation>

class Deplacement : public QState
{
    Q_OBJECT
public:
    Deplacement( QPropertyAnimation *vanime, QState *vparent );

protected:
    virtual void onEntry(QEvent *);
    virtual void onExit(QEvent *);

private:
    QPropertyAnimation *animation;

};

#endif // DEPLACEMENT_H

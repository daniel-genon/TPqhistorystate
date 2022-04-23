#ifndef HISTOPERSO_H
#define HISTOPERSO_H

#include <QHistoryState>

class HistoPerso : public QHistoryState
{
    Q_OBJECT
public:
    HistoPerso(QObject *vcible, QState *vparent = nullptr);

protected:
    virtual void onEntry(QEvent*);
    virtual void onExit(QEvent*);

private :
    QObject *pcible;

};

#endif // HISTOPERSO_H

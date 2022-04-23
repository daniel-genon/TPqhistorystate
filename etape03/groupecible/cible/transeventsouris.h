#ifndef TRANSEVENTSOURIS_H
#define TRANSEVENTSOURIS_H

#include <QEventTransition>

class TransEventSouris : public QEventTransition
{
    Q_OBJECT
public:
    TransEventSouris( QObject *dobject, QEvent::Type dtype, QState *source );

protected:
    virtual bool eventTest( QEvent *evt);

};

#endif // TRANSEVENTSOURIS_H

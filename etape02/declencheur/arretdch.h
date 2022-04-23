#ifndef ARRETDCH_H
#define ARRETDCH_H

#include "declencheur.h"
class ArretDch : public QState
{
    Q_OBJECT
public:
    ArretDch( Declencheur *vdcl, QState *vparent = 0 );
    ~ArretDch();
signals :
    void RePositionner();
protected:
    virtual void onEntry(QEvent *);
private:
    Declencheur *declencheur;
};

#endif // ARRETDCH_H

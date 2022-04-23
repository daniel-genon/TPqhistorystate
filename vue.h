#ifndef VUE_H
#define VUE_H

#include <QGraphicsView>
class Vue : public QGraphicsView
{
public:
    Vue(QGraphicsScene *scene, QWidget *parent = Q_NULLPTR);
};

#endif // VUE_H

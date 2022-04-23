#ifndef OBJETIMAGE_H
#define OBJETIMAGE_H

#include <QGraphicsObject>

class ObjetImage : public QGraphicsObject
{
public:
    ObjetImage( QGraphicsItem* parent=0);
    ObjetImage(const QString &nomfichier, QGraphicsItem *parent=0);
    void InitImage(const QString &nomfich);
    void ChangeImage(const QString &nomfich);
    QSizeF size() const;

protected:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget *);

private:
    QPixmap         image;
};

#endif // OBJETIMAGE_H

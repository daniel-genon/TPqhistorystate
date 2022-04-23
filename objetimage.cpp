#include "objetimage.h"
#include <QPainter>
ObjetImage::ObjetImage( QGraphicsItem *parent ):QGraphicsObject(parent)
{
    InitImage(":/motif/main1.png");
}

ObjetImage::ObjetImage( const QString &nomfichier,QGraphicsItem* parent ): QGraphicsObject(parent)
{
    InitImage(nomfichier);
}

void ObjetImage::InitImage( const QString &nomfich )
{
    image=QPixmap(nomfich);
}
void ObjetImage::ChangeImage( const QString &nomfich )
{
    image.load(nomfich);
}

QSizeF ObjetImage::size()const { return image.size();}
QRectF ObjetImage::boundingRect() const
{
    return QRectF(QPointF(0, 0), image.size());
}
void ObjetImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0, 0, image);
}



#include "apple.h"

apple::apple(QObject *parent): QObject(parent), QGraphicsItem()
{

}
apple::~apple()
{

}

QRectF apple::boundingRect() const
{
    return QRectF(-25, -25, 50, 50);
}

void apple::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap("://assets/images/apple.png");
    painter->drawPixmap(boundingRect().toRect(), pixmap);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}




#ifndef APPLE_H
#define APPLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
class apple :public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit apple(QObject *parent = 0);
    ~apple();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // APPLE_H

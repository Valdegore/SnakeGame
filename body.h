
#ifndef BODY_H
#define BODY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QTimer>


class body :public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit body(QObject *parent = 0);
    ~body();
    static QList<QGraphicsItem *> partbody;
    QTimer *bodyTimer;
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QPainterPath shape() const;
public slots:
        void slotStopGame3();
private slots:
    void slotBodyTimer();   // igrowy slot
};


#endif // BODY_H

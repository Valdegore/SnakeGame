
#ifndef SNAKE_H
#define SNAKE_H




#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPolygon>
#include <QTimer>
#include <QDebug>
#include <QCursor>
#include <QPixmap>
#include <QList>

class Snake : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Snake(QObject *parent = 0);
    ~Snake();
    static QList<QPointF> snakeHeadPositions;
    QTimer *gameTimer;      // tajmer
signals:
    void signalCheckItem(QGraphicsItem *item);
    void signalkoniec1();

public slots:
    // slot dla położenia kursoru
    void slotTarget(QPointF point);
    void slotStopGame2();


private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;     // forma obiektu dla kolizji
    QPointF target;         // zmienna przechowująca położenie myszki


private slots:
    void slotGameTimer();   // igrowy slot
};

#endif // SNAKE_H

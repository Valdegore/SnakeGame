
#include "body.h"
#include "snake.h"
#include <QDebug>
#include "start.h"
body::body(QObject *parent): QObject(parent), QGraphicsItem()
{
    bodyTimer = new QTimer();   // tajmer igrowy
    // podłączenie signalu od tajmera do slotu opracowania tajmera
    connect(bodyTimer, &QTimer::timeout, this, &body::slotBodyTimer);
    bodyTimer->start(5);   // start tajmer
}
QList<QGraphicsItem *> body::partbody;
body::~body()
{

    partbody.clear();
}

QRectF body::boundingRect() const
{
    return QRectF(-50, -50, 100, 100);
}

QPainterPath body::shape() const
{
    QPainterPath path;
    qreal radius = 20.0; // Promień koła

    // Oblicz środek koła na podstawie boundingRect
    qreal centerX = boundingRect().center().x();
    qreal centerY = boundingRect().center().y();

    path.addEllipse(centerX - radius, centerY - radius, radius * 2, radius * 2);
    return path;
}

void body::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap("://assets/images/cialo.png");
    painter->drawPixmap(boundingRect().toRect(), pixmap);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void body::slotBodyTimer()
{
    int j =0;
    int index = 0;
    for(int i=0; i<body::partbody.size();i++){
        index = j + 30;
        body::partbody[i]->setPos(Snake::snakeHeadPositions[index]);

        j+=24;
    }

}
void body::slotStopGame3(){

    bodyTimer->stop();
}

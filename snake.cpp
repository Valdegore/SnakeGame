
#include "snake.h"
#include <QVector2D>
#include <QDebug>
#include <math.h>
#include "body.h"


static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}
QList<QPointF> Snake::snakeHeadPositions(1000);

Snake::Snake(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    setRotation(0);      // początkowy kąt obiektu

    target = QPointF(0,0);  // położenie myszki początkowe

    gameTimer = new QTimer();   // tajmer igrowy
    // podłączenie signalu od tajmera do slotu opracowania tajmera
    connect(gameTimer, &QTimer::timeout, this, &Snake::slotGameTimer);
    gameTimer->start(5);   // start tajmer

}

Snake::~Snake()
{
snakeHeadPositions.clear();
}

// rozmiar i centrowanie obiektu
QRectF Snake::boundingRect() const
{
    return QRectF(-50,-50,100,100);
}

// forma głowy
QPainterPath Snake::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ustawienie obrazka dla węża
    QPixmap pixmap("://assets/images/glowa2.png");
    painter->drawPixmap(boundingRect().toRect(), pixmap);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void Snake::slotTarget(QPointF point)
{
    // odległość do myszki
    target = point;
    QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));
    //kąt obracania
    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

    // wybór w jaką strone obracać się
    if (angleToTarget >= 0 && angleToTarget < Pi) {
        /// Rotate left
        setRotation(rotation() - angleToTarget * 180 /Pi);
    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
        /// Rotate right
        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
    }

}


void Snake::slotGameTimer()
{
    // ruch węża

    QPointF currentPosition = this->pos();
    qreal speed = 1.5;
    QVector2D direction = QVector2D(target - currentPosition).normalized();
    this->setPos(currentPosition + direction.toPointF() * speed);


    // czy jest węż za polem
    if(this->x() - 65 < 0){
        emit signalkoniec1();
        //this->setX(65);         /// left
    }
    if(this->x() + 65 > 1490){
        emit signalkoniec1();
        //this->setX(1490 - 65);   /// right
    }

    if(this->y() - 60 < 0){
        emit signalkoniec1();
        //this->setY(60);         /// up
    }
    if(this->y() + 60 > 750){
        emit signalkoniec1();
        //this->setY(750 - 60);   /// down
    }




    for (int i = snakeHeadPositions.size() - 1; i >= 0; i--) {
        if (i > 0) {
            Snake::snakeHeadPositions[i] = Snake::snakeHeadPositions[i - 1];
        } else {
            Snake::snakeHeadPositions[i] = this->pos();
        }
    }




    QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));
    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);


    if (angleToTarget >= 0 && angleToTarget < Pi) {
        /// Rotate left
        setRotation(rotation() - angleToTarget * 180 /Pi);
    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
        /// Rotate right
        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
    }
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                       << mapToScene(0, 0)
                                                       << mapToScene(15, -15)
                                                       << mapToScene(-15, -15));

    foreach (QGraphicsItem *item, foundItems) {
        if (item == this)
            continue;
        else if(body::partbody.contains(item)){
            emit signalkoniec1();
            qDebug() << "To jest komunikat w konsoli.";
        }
        emit signalCheckItem(item);

    }

}

void Snake::slotStopGame2(){

    gameTimer->stop();
}

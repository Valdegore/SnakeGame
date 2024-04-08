#ifndef START_H
#define START_H


#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QDebug>

#include "customscene.h"

#include "snake.h"

namespace Ui {
class Start;
}

class Start : public QWidget
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();
    static int ile;

private:
    Ui::Start *ui;
    customScene  *scene;
    Snake *snake;

    QTimer *timerCreateApple;

    QList<QGraphicsItem *> apples;  // lista z jabłkami

private slots:
    void slotCreateApple();
    void slotStopGame();

    void slotDeleteApple(QGraphicsItem * item);
};

#endif // START_H

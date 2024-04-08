#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H




#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class customScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit customScene(QObject *parent = 0);
    ~customScene();

signals:
         // signal dla przekazania położenia
    void signalTargetCoordinate(QPointF point);

public slots:

private:
    //funkcja dla sledzebia
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMSCENE_H

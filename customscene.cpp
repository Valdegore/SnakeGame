#include "customscene.h"

customScene::customScene(QObject *parent) :
    QGraphicsScene()
{
    Q_UNUSED(parent);
}

customScene::~customScene()
{

}

void customScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalTargetCoordinate(event->scenePos());
}



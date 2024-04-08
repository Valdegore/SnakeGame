#include "updater.h"
#include <QDebug>

Updater::Updater(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000/60);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start();
    timer->stop();
}

void Updater::update()
{
    qDebug() << "Updating...";
    // Wywołujemy funkcję update() na innych obiektach, które mają być odświeżane co określony czas
}

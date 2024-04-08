#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>
#include <QTimer>

class Updater : public QObject
{
    Q_OBJECT

public:
    Updater(QObject *parent = nullptr);

public slots:
    void update();

private:
    QTimer* timer;
};

#endif // UPDATER_H

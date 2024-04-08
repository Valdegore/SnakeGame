#include "mainwindow.h"
#include "data/scripts/components/musicmanager.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MusicManager music;
    MusicManager::play("/assets/music/15. Resting Grounds.mp3");
    MainWindow w;
    w.show();
    return a.exec();
    //
}

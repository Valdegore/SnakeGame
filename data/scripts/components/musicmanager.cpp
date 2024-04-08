#include "MusicManager.h"
#include <QDebug>

/*MusicManager& MusicManager::instance()
{
    static MusicManager instance;
    return instance;
}

MusicManager::MusicManager() : QObject()
{
    player = new QMediaPlayer(this);
    player->setAudioOutput(&output);
}

void MusicManager::play(QString song)
{
    qDebug() << song;
    player->setSource(QUrl("qrc:"+song));
    player->setLoops(-1);
    player->play();
}

void MusicManager::setLoop(bool isloop)
{
    if (isloop) {player->setLoops(-1);} else {player->setLoops(0); }
}

void MusicManager::setVolume(int vol)
{
}

void MusicManager::stop()
{
    player->setLoops(0);
    player->stop();
}

MusicManager::~MusicManager()
{
    delete player;
}*/

MusicManager *MusicManager::instance = nullptr;
QMediaPlayer *MusicManager::player = nullptr;
QAudioOutput *MusicManager::output=nullptr;

MusicManager::MusicManager(){
    Q_ASSERT(instance == nullptr);
    instance = this;
    player = new QMediaPlayer();
    output = new QAudioOutput();
    player->setAudioOutput(output);
}

MusicManager::~MusicManager(){
    Q_ASSERT(instance != nullptr);
    instance = nullptr;
}

void MusicManager::play(QString song)
{
    player->setSource(QUrl("qrc:"+song));
    player->setLoops(-1);
    player->play();
}
void MusicManager::setLoop(bool isloop)
{
    if (isloop) {player->setLoops(-1);} else {player->setLoops(0); }
}
void MusicManager::setVolume(int vol)
{
    output->setVolume(vol);
}

/*void MusicManager::setMute(bool val){
    output->setMuted(val);
}*/

void MusicManager::stop()
{
    player->setLoops(0);
    player->stop();
}

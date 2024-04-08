#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class MusicManager : public QObject
{
    Q_OBJECT
public:
    MusicManager();
    ~MusicManager();
    static void play(QString song);
    void setLoop(bool isloop);
    static void setVolume(int vol);
    static void stop();

   /* static MusicManager& instance();
    void play(QString song);
    void setLoop(bool isloop);
    void setVolume(int vol);
    void stop();*/

private:
    /*explicit MusicManager();
    MusicManager(const MusicManager&) = delete;
    MusicManager& operator=(const MusicManager&) = delete;
    ~MusicManager();
    QMediaPlayer* player;
    QAudioOutput output;*/

    static MusicManager *instance;
    static QMediaPlayer *player;
    static QAudioOutput *output;
};

#endif // MUSICMANAGER_H

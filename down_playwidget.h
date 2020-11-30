#ifndef DOWN_PLAYWIDGET_H
#define DOWN_PLAYWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QtMultimedia/QMediaPlayer>

class down_playWidget: public QWidget
{
    Q_OBJECT
public:
    explicit down_playWidget(QWidget* parent);
    QPushButton* m_btnPlay;
    QPushButton* m_btnPrevSong;
    QPushButton* m_btnNextSong;
    QMediaPlayer* m_mediaPlayer;
};

#endif // DOWN_PLAYWIDGET_H

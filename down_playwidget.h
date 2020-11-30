#ifndef DOWN_PLAYWIDGET_H
#define DOWN_PLAYWIDGET_H
#pragma once
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QStringListIterator>

class Down_PlayWidget: public QWidget
{
    Q_OBJECT
public:
    explicit Down_PlayWidget(QWidget* parent);
    QPushButton* m_btnPlay;
    QPushButton* m_btnPrevSong;
    QPushButton* m_btnNextSong;
    QMediaPlayer* m_mediaPlayer;
};

#endif // DOWN_PLAYWIDGET_H

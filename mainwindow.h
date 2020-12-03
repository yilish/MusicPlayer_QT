#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include "down_playwidget.h"
#include "down_voicewidget.h"
#include "down_playlistbutton.h"
#include "down_playlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void updateMusicWidget();
    void playNextSong();
    void playPrevSong();
    void mute();
    void showPlayList();
private:
    Ui::MainWindow *ui;
    QWidget* m_downWidget;
    QMediaPlayer* m_mediaPlayer;
    QMediaPlaylist* m_mediaPlayList;
    Down_PlayWidget* m_downPlayWidget;
    Down_VoiceWidget* m_downVoiceWidget;
    Down_PlayListButton* m_downBtnPlayList;   //播放列表按钮
    Down_PlayList* m_showPlayList;  //显示播放列表
    void setDownWidget(QWidget* widget);

};
#endif // MAINWINDOW_H

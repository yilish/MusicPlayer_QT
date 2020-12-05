#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include "down_playwidget.h"
#include "down_voicewidget.h"
#include "down_playprogressbar.h"
#include "down_playlistbutton.h"
#include "down_playlist.h"
#include "left_table.h"

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
    void changeVolVal(int val);
    void changePlayProgress(int val);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void showPlayList();
private:
    Ui::MainWindow *ui;
    QWidget* m_downWidget;
    QString m_tDuration;
    QString m_tPosition;
    QMediaPlayer* m_mediaPlayer;
    QMediaPlaylist* m_mediaPlayList;
    Down_PlayWidget* m_downPlayWidget;
    Down_VoiceWidget* m_downVoiceWidget;
    Down_PlayProgressBar* m_downProgressBar;
    Down_PlayListButton* m_downBtnPlayList;   //播放列表按钮
    Down_PlayList* m_showPlayList;  //显示播放列表
    Left_Table* m_leftTable;
    void setDownWidget(QWidget* widget);
    void setLeftWidget(QWidget* widget);
    int m_unMutedVol;
};
#endif // MAINWINDOW_H

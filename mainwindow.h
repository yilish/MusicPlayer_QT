#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include "down_playwidget.h"
#include "down_voicewidget.h"
#include "down_playprogressbar.h"
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

    void setDownWidget(QWidget* widget);
    int m_unMutedVol;
};
#endif // MAINWINDOW_H

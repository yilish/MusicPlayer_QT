#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include "down_playwidget.h"
#include "down_voicewidget.h"

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
private:
    Ui::MainWindow *ui;
    QWidget* m_downWidget;
    QMediaPlayer* m_mediaPlayer;
    QMediaPlaylist* m_mediaPlayList;
    Down_PlayWidget* m_downPlayWidget;
    Down_VoiceWidget* m_downVoiceWidget;
    void setDownWidget(QWidget* widget);
    int m_unMutedVol;
};
#endif // MAINWINDOW_H

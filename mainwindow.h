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
#include "middle_searchresult.h"
#include "top_searchwidget.h"
#include <QNetworkAccessManager>
#include <QStringList>
#include "left_table.h"
#include "database.h"
#include "middle_musicshow.h"
#include "lyricloader.h"
#include "left_musicshowwidget.h"
#include "left_musicbutton.h"
#include "song.h"
#include "lyricwindow.h"
#include <QList>
#include "lyricline.h"
#include "songsheet.h"
#include "middle_wheelpic.h"


#include <QInputDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

private slots:
    void updateMusicShowWidget(QMediaContent media);
    void updateMusicWidget();
    void playNextSong();
    void playPrevSong();
    void mute();
    void changeVolVal(int val);
    void changePlayProgress(int val);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void showPlayList();
    void searchSong();
    void showMinWindow();
    void showMusicWidget();
    //void updateDownloadProgress(qint64 bytesRead,qint64 totalBytes);
    void firstFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);
    void httpFinished();
    void downloadSelectedSong(const QModelIndex &index);
    void urlRedirected();
    void doProcessError(QNetworkReply::NetworkError code);
    void lyricRead();
    void playmodeChanged();
    void playListChange();
    void closeMainwindow();
    void LocalListClick();
    void LeftTableClick();
    void removeBtnClicked();
    void myMusicClicked();
    void creatSongSheetClicked();
    void mySongSheetClicked();
    void likeBtnClicked();
    void addToSongSheetClicked();
    void backToHome();
private:
    //void keyPressEvent(QKeyEvent *event);
    void setDownWidget(QWidget* widget);
    void setTopWidget(QWidget* widget);
    void createRedLine();
    void setLeftWidget();
    void createFolder(QString folder);
    QString getSongId(QJsonObject obj);
    QString getArtistName(QJsonObject obj);
    void mousePressEvent(QMouseEvent *e);
    bool isInRange(QPoint p,QWidget* widget);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

    bool m_pressed = false;

    Ui::MainWindow *ui;
    QLabel* m_lblLogo;
    QPoint m_point;
    QWidget* m_downWidget;
    QWidget* m_topWidget;
    QWidget* m_redWidget;


    QWidget* m_leftWidget;
    QString m_tDuration;
    QString m_tPosition;
    QPushButton* m_btnMinimum;
    QPushButton* m_btnClose;

    QMediaPlayer* m_mediaPlayer;
    QMediaPlaylist* m_mediaPlayList;
    Down_PlayWidget* m_downPlayWidget;
    Down_VoiceWidget* m_downVoiceWidget;
    Down_PlayProgressBar* m_downProgressBar;
    Down_PlayListButton* m_downBtnPlayList;   //播放列表按钮
    Down_PlayList* m_showPlayList;  //显示播放列表
    Middle_musicShow* m_middleMusicShow;
    Middle_WheelPic* m_middleWheelPic;
    Left_musicShowWidget* m_leftMusicShowWidget;
    Left_MusicButton* m_leftBtnFullScreen;


    QNetworkAccessManager* m_accessManager;
    QNetworkRequest m_request;
    QNetworkReply* m_reply;
    QNetworkReply* m_lyricReply;
    QNetworkReply* m_albumReply;

    QFile* m_lyricFile;
    QFile* m_albumFile;
    QString m_curSongName;
    QNetworkAccessManager* m_redirAccMgr;
    QNetworkRequest m_redirectedRequest;
    QNetworkReply* m_redirectedReply;
    Top_SearchWidget* m_topSearchWidget;
    Middle_searchResult* m_searchResult;
    QProgressBar* m_downloadProgressBar;
    QJsonArray m_songArr;
    QFile* m_curFile;
    Left_Table* m_leftTable;
    QString songName;   //store downloading song's name
    QString artistName; //store downloading song's artist
    QString id; //store the id of downloading song
    QString filePath;    //store the dir of downloaded song
    QString albumName;  //store albumName image dir
    QString lyricFileName;
    QString coverLink;
    DataBase m_database;    //database that stores songs' information
                            //songname, artistname, song-artist, dir
    int m_unMutedVol;
    int m_playMode;
    LyricLoader m_lyricLoader;
    LyricWindow* m_lyricwindow;
    SongSheet* m_LocalMusic;
    QList<SongSheet*> m_SongSheetList;
    QList<QString> m_likes;
protected:
    bool eventFilter(QObject *obj, QEvent *event);

};
#endif // MAINWINDOW_H

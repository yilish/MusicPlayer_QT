#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //UI设计
    //ui->setupUi(this);
    setMaximumSize(1300,800);
    setMinimumSize(1300,800);//固定软件界面的大小
    //setWindowFlags(Qt::FramelessWindowHint|windowFlags());//实现无边框


    //边框初始化
    //下边框初始化
    m_downWidget = new QWidget(this);
    setDownWidget(m_downWidget);
    m_downPlayWidget = new Down_PlayWidget(m_downWidget);
    m_downPlayWidget->setGeometry(0,0,250,70);


    m_downVoiceWidget = new Down_VoiceWidget(m_downWidget);
    m_downVoiceWidget->setGeometry(940, 0, 180, 70);
    //播放器初始化
    m_mediaPlayer = new QMediaPlayer(this);
    m_downPlayWidget->setMediaPlayer(m_mediaPlayer);


    //init of play list
    m_mediaPlayList = new QMediaPlaylist(this);
    m_mediaPlayList->setPlaybackMode(QMediaPlaylist::Loop);
    m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test.mp3"));
    m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test1.mp3"));
   // m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test2.mp3"));
    m_mediaPlayList->setCurrentIndex(0);

    //bind list with player
    m_mediaPlayer->setPlaylist(m_mediaPlayList);
    m_mediaPlayer->setVolume(30);
    m_unMutedVol = 30;


    //m_mediaPlayer->play();

    //连接信号与槽
    connect(m_downPlayWidget->m_btnPlay, SIGNAL(clicked(bool)), this, SLOT(updateMusicWidget()));
    connect(m_downPlayWidget->m_btnNextSong, SIGNAL(clicked(bool)), this, SLOT(playNextSong()));
    connect(m_downPlayWidget->m_btnPrevSong, SIGNAL(clicked(bool)), this, SLOT(playPrevSong()));



    connect(m_downVoiceWidget->m_btnMute, SIGNAL(clicked(bool)), this, SLOT(mute()));
    connect(m_downVoiceWidget->m_sliderVol, SIGNAL(valueChanged(int)), this, SLOT(changeVolVal(int)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateMusicWidget() {
    if (m_downPlayWidget->m_btnPlay->isChecked()) {
        //播放列表空否？
        if (!m_mediaPlayList->isEmpty()) {
            m_mediaPlayer->play();
        }
    }

    else {
        m_mediaPlayer->pause();
    }

}

void MainWindow::playNextSong() {
    auto nextIndex = (m_mediaPlayList->currentIndex() + 1) % m_mediaPlayList->mediaCount();
    // calculate the index of next song by mod the max size of total media.
    m_mediaPlayList->setCurrentIndex(nextIndex);

}

void MainWindow::playPrevSong() {
    auto nextIndex = (m_mediaPlayList->currentIndex() - 1) % m_mediaPlayList->mediaCount();
    m_mediaPlayList->setCurrentIndex(nextIndex);
}

void MainWindow::mute() {
    if (! m_downVoiceWidget->m_btnMute->isChecked()) {
        //设置default音量
        m_mediaPlayer->setVolume(m_unMutedVol);
        m_downVoiceWidget->m_sliderVol->setValue(m_unMutedVol);
    }
    else {
        m_mediaPlayer->setVolume(0);
        m_downVoiceWidget->m_sliderVol->setValue(0);
    }

}

void MainWindow::changeVolVal(int val) {
    if (m_downVoiceWidget->m_btnMute->isChecked() && val != 0) {
        m_downVoiceWidget->m_btnMute->setChecked(false);
    }
    if (val != 0){  //否则unmutedvol永远是0
        m_unMutedVol = val;
    }
    m_mediaPlayer->setVolume(val);
}

void MainWindow::setDownWidget(QWidget *widget) {

    widget->setGeometry(0,730,1300,70);
    QPalette pal(widget->palette());
    pal.setColor(QPalette::Background,QColor(50,50,50));
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    //widget->show();
}



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



    //下载进度条的初始化
    m_downloadProgressBar = new QProgressBar(this);
    m_downloadProgressBar->setGeometry(400, 200, 300, 50);
    m_downloadProgressBar->hide();



    //边框初始化
    //下边框初始化
    m_downWidget = new QWidget(this);
    setDownWidget(m_downWidget);


    //左侧菜单初始化
    m_leftTable = new Left_Table(this);
    m_leftTable->setGeometry(0, 0, 300, 730);


    m_downPlayWidget = new Down_PlayWidget(m_downWidget);
    m_downPlayWidget->setGeometry(0,0,250,70);
    m_downVoiceWidget = new Down_VoiceWidget(m_downWidget);
    m_downVoiceWidget->setGeometry(940, 0, 180, 70);


    //上边框初始化
    m_topWidget = new QWidget(this);
    setTopWidget(m_topWidget);
    m_topSearchWidget = new Top_SearchWidget(m_topWidget);
    m_topSearchWidget->setGeometry(348, 20, 360, 48);
    //搜索栏初始化
    //起始位置: 315, 65
    //大小: 360, (500)?
    m_searchResult = new Middle_searchResult(this);
    m_searchResult->setGeometry(348, 65, 330, 500);
    //播放器初始化
    m_mediaPlayer = new QMediaPlayer(this);
    m_downPlayWidget->setMediaPlayer(m_mediaPlayer);


    //播放列表可视化
    m_downBtnPlayList = new Down_PlayListButton(m_downWidget);
    m_downBtnPlayList->setGeometry(1220, 0, 180, 70);
    m_showPlayList = new Down_PlayList(this);


    //init of play list
    m_mediaPlayList = new QMediaPlaylist(this);
    m_mediaPlayList->setPlaybackMode(QMediaPlaylist::Loop);
    m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test.mp3"));
    m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test1.mp3"));
    //m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test2.mp3"));
    m_mediaPlayList->setCurrentIndex(0);

    //bind list with player
    m_mediaPlayer->setPlaylist(m_mediaPlayList);
    m_mediaPlayer->setVolume(30);
    m_unMutedVol = 30;

    //播放进度条初始化

    m_downProgressBar = new Down_PlayProgressBar(m_downWidget);

    m_downProgressBar->setGeometry(250, 0, 690, 70);
    //auto durTime = m_mediaPlayer->position();
    m_downProgressBar->update();
    //连接信号与槽
    connect(m_downPlayWidget->m_btnPlay, SIGNAL(clicked(bool)), this, SLOT(updateMusicWidget()));
    connect(m_downPlayWidget->m_btnNextSong, SIGNAL(clicked(bool)), this, SLOT(playNextSong()));
    connect(m_downPlayWidget->m_btnPrevSong, SIGNAL(clicked(bool)), this, SLOT(playPrevSong()));
    connect(m_downVoiceWidget->m_btnMute, SIGNAL(clicked(bool)), this, SLOT(mute()));
    connect(m_downVoiceWidget->m_sliderVol, SIGNAL(valueChanged(int)), this, SLOT(changeVolVal(int)));
    connect(m_mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(onPositionChanged(qint64)));
    connect(m_mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));
    connect(m_downProgressBar->m_sliderPlayProgress, SIGNAL(valueChanged(int)), this, SLOT(changePlayProgress(int)));
    connect(m_downBtnPlayList->m_btnPlayList, SIGNAL(clicked(bool)), this, SLOT(showPlayList()));

    connect(m_topSearchWidget->m_btnSearch, SIGNAL(clicked()), this, SLOT(searchSong()));
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
    if (m_mediaPlayList->isEmpty()) {
        return;
    }
    auto nextIndex = (m_mediaPlayList->currentIndex() + 1) % m_mediaPlayList->mediaCount();
    // calculate the index of next song by mod the max size of total media.
    m_mediaPlayList->setCurrentIndex(nextIndex);
    if (! m_downPlayWidget->m_btnPlay->isChecked()) {
        m_downPlayWidget->m_btnPlay->setChecked(true);
        m_mediaPlayer->play();
    }
}

void MainWindow::playPrevSong() {
    if (m_mediaPlayList->isEmpty()) {
        return;
    }
    auto nextIndex = (m_mediaPlayList->currentIndex() - 1) % m_mediaPlayList->mediaCount();
    // calculate the index of next song by mod the max size of total media.
    m_mediaPlayList->setCurrentIndex(nextIndex);
    if (! m_downPlayWidget->m_btnPlay->isChecked()) {
        m_downPlayWidget->m_btnPlay->setChecked(true);
        m_mediaPlayer->play();
    }
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

void MainWindow::changePlayProgress(int val) {
    if (! m_mediaPlayList->mediaCount()) {
        return;
    }
    if (qAbs(m_mediaPlayer->position() - val)> 99) {
        m_mediaPlayer->setPosition(val);
    }


}

void MainWindow::onDurationChanged(qint64 duration){
    if (! m_mediaPlayList->mediaCount()) {
        return;
    }
    m_downProgressBar->m_sliderPlayProgress->setMaximum(duration);

    int sec = duration / 1000;      //秒数
    int min = sec / 60;
    sec %= 60;
    if (sec < 10) {
        m_tDuration = QString::asprintf("%d:0%d", min, sec);
    }
    else {
        m_tDuration = QString::asprintf("%d:%d", min, sec);
    }
    m_downProgressBar->m_lblRight->setText(m_tDuration);

}

void MainWindow::onPositionChanged(qint64 position) {
    if (m_downProgressBar->m_sliderPlayProgress->isSliderDown()) {
        return;
    }

    m_downProgressBar->m_sliderPlayProgress->setSliderPosition(position);
    int sec = position / 1000;      //秒数
    int min = sec / 60;
    sec %= 60;
    if (sec < 10) {
        m_tPosition = QString::asprintf("%d:0%d", min, sec);
    }
    else {
        m_tPosition = QString::asprintf("%d:%d", min, sec);
    }
    m_downProgressBar->m_lblLeft->setText(m_tPosition);
}

void MainWindow::setDownWidget(QWidget *widget) {

    widget->setGeometry(0,730,1300,70);
    QPalette pal(widget->palette());
    pal.setColor(QPalette::Background,QColor(50,50,50));
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    //widget->show();
}


void MainWindow::setTopWidget(QWidget *widget) {
    widget->setGeometry(0, 0, 1300, 65);
    QPalette pal(widget->palette());

    pal.setColor(QPalette::Background, QColor(50, 50, 50));
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    widget->show();
}

void MainWindow::createFolder(QString folder) {
    QDir* newFolder = new QDir;
    bool exist = newFolder->exists(folder);

    if (exist) {
        qDebug() << "This folder" << folder << "already exists" << endl;
    }
    else {
        newFolder->mkdir(folder);
    }
}

QString MainWindow::getSongId(QJsonObject obj) {
    auto doubleId = obj.value("id").toDouble();

    QString strId = QString::number(doubleId, 'f', 0);

    return strId;
}

QString MainWindow::getArtistName(QJsonObject obj) {
    auto artistArr = obj.value("artists");
    auto artistObj = artistArr[0];
    auto artistName = artistObj["name"];
    auto strArtistName = artistName.toString();
    return strArtistName;
}

void MainWindow::showPlayList() {

    if(!m_showPlayList->isVisible()) {
        m_showPlayList->show();
        m_showPlayList->setGeometry(800, 0, 500, 730);
    }
    else {
        m_showPlayList->hide();
    }
}

void MainWindow::searchSong() {
    auto strToSearch = m_topSearchWidget->m_lineSearch->text();
    qDebug() << "Hello" + strToSearch.toLatin1();
    QUrl netEaseUrl = QUrl("http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s=" +strToSearch + "&type=1&offset=0&total=true&limit=10");
    QUrl url = QUrl("https://api.paugram.com/netease/?title=" + strToSearch);
    QNetworkAccessManager manager;
    QNetworkReply* searchReply = manager.get(QNetworkRequest(netEaseUrl));
    QEventLoop loop;
    connect (searchReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();


    if (searchReply->error() == QNetworkReply::NoError) {
        QByteArray array = searchReply->readAll();
        QJsonParseError jsonErr;
        QJsonDocument json = QJsonDocument::fromJson(array, &jsonErr);
        QStringList strList;
        if (jsonErr.error == QJsonParseError::NoError) {
            QJsonObject obj = json.object();
            //处理搜索到的结果

            auto res = obj["result"].toObject();
            auto songsArr = res["songs"].toArray();
            for (int i = 0; i < songsArr.size(); i++) {
                auto objSong = songsArr[i].toObject();
                auto id = getSongId(objSong);
                auto artistName = getArtistName(objSong);
                strList.push_back(artistName + objSong["name"].toString());
                qDebug() << objSong["name"].toString() << artistName;
            }

            m_searchResult->setList(&strList);


            auto objSong0 = songsArr[0].toObject();
            auto doubleId = objSong0.value("id").toDouble();

            QString strId = QString::number(doubleId, 'f', 0);
            qDebug() << doubleId << strId;



            auto absPath = QApplication::applicationDirPath();
            auto dir = QApplication::applicationDirPath() + QString("/music/");
            createFolder(dir);
            auto artistArr = objSong0.value("artists");
            auto artistObj = artistArr[0];
            auto artistName = artistObj["name"];
            auto strArtistName = artistName.toString();
            auto filePath = dir  + strArtistName + "-" + objSong0["name"].toString() + ".mp3";
            qDebug() << "FilePath:" << filePath;
            m_curFile = new QFile(filePath);

            m_curFile->open(QIODevice::WriteOnly);

            m_accessManager = new QNetworkAccessManager(this);
            m_request = QNetworkRequest();

            auto link = QString("https://music.163.com/song/media/outer/url?id=" + strId);
            m_request.setUrl(link);
            m_reply = m_accessManager->get(m_request);

            m_downloadProgressBar->show();

            connect(m_reply,&QNetworkReply::finished,this,&MainWindow::firstFinished);
            // ToDo: 下载完成后加入自动扫描到歌单的功能
        }
    }

}

void MainWindow::firstFinished() {
    auto redirUrl = m_reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    m_request.setUrl(redirUrl.toString());
    m_reply = m_accessManager->get(m_request);
    connect(m_reply,&QNetworkReply::readyRead,this,&MainWindow::httpReadyRead);
    connect(m_reply,&QNetworkReply::downloadProgress,this,&MainWindow::updateDataReadProgress);
    connect(m_reply,&QNetworkReply::finished,this,&MainWindow::httpFinished);
}


void MainWindow::httpReadyRead() {
    if (m_curFile) {
        m_curFile->write(m_reply->readAll());
    }
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes) {
    m_downloadProgressBar->setMaximum(totalBytes);

    m_downloadProgressBar->setValue(bytesRead);
}

void MainWindow::httpFinished() {
    m_downloadProgressBar->hide();

    if (m_curFile) {
        m_curFile->close();
        delete m_curFile;
        m_curFile = nullptr;
    }
}

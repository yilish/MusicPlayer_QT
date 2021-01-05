#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //初始化数据库
    m_database.createConnection();
    m_database.createTable();



    //UI设计
    //ui->setupUi(this);
    setMaximumSize(1300,800);
    setMinimumSize(1300,800);//固定软件界面的大小
    //setWindowFlags(Qt::FramelessWindowHint|windowFlags());//实现无边框



    //下载进度条的初始化
    m_downloadProgressBar = new QProgressBar(this);
    m_downloadProgressBar->setGeometry(348, 500, 300, 50);
    m_downloadProgressBar->hide();



    //边框初始化
    //下边框初始化
    m_downWidget = new QWidget(this);
    setDownWidget(m_downWidget);


    //左侧菜单初始化
    m_leftWidget = new QWidget(this);
    setLeftWidget();
    //m_leftTable = new Left_Table(this);
    //m_leftTable->setGeometry(0, 0, 300, 730);
    m_leftBtnFullScreen = new Left_MusicButton(m_leftWidget);
    m_leftBtnFullScreen->setGeometry(0,597,250,64);
    connect(m_leftBtnFullScreen,SIGNAL(clicked(bool)),this,SLOT(showMusicWidget()));

    m_downPlayWidget = new Down_PlayWidget(m_downWidget);
    m_downPlayWidget->setGeometry(0,0,1300,70);
    m_downVoiceWidget = new Down_VoiceWidget(m_downWidget);
    m_downVoiceWidget->setGeometry(940, 0, 180, 70);

    m_leftMusicShowWidget = new Left_musicShowWidget(this);
    m_leftMusicShowWidget->setGeometry(0,730,0,0);

    //上边框初始化
    m_topWidget = new QWidget(this);
    setTopWidget(m_topWidget);
    m_topSearchWidget = new Top_SearchWidget(m_topWidget);
    m_topSearchWidget->setGeometry(348, 20, 360, 48);
    //搜索栏初始化
    //起始位置: 315, 65
    //大小: 360, (500)?
    m_middleMusicShow = new Middle_musicShow(this);
    m_middleMusicShow->lower();
    m_middleMusicShow->setGeometry(250,69,1050,661);

    //歌词窗体QLabel
    m_lyricWindow = new LyricWindow(this);
    QFont ft;
    ft.setPointSize(12);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    m_lyricWindow->setFont(ft);
    m_lyricWindow->setPalette(pa);


    m_searchResult = new Middle_searchResult(this);
    m_searchResult->setGeometry(348, 65, 330, 500);
    m_searchResult->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可更改里面的内容
    m_searchResult->hide();             //默认不出现
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
    //m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test.mp3"));
    //m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test1.mp3"));
    //m_mediaPlayList->addMedia(QUrl::fromLocalFile("D:/DSproj/music/test2.mp3"));
    m_mediaPlayList->setCurrentIndex(0);

    //bind list with player
    m_mediaPlayer->setPlaylist(m_mediaPlayList);
    m_mediaPlayer->setVolume(30);
    m_unMutedVol = 30;
    m_playMode = 0;
    //播放进度条初始化

    m_downProgressBar = new Down_PlayProgressBar(m_downWidget);
    m_downloadProgressBar->raise();
    m_downProgressBar->setGeometry(250, 0, 690, 70);
    //auto durTime = m_mediaPlayer->position();
    m_downProgressBar->update();
    //连接信号与槽
    connect(m_downPlayWidget->m_btnPlay, SIGNAL(clicked(bool)), this, SLOT(updateMusicWidget()));
    connect(m_downPlayWidget->m_btnNextSong, SIGNAL(clicked(bool)), this, SLOT(playNextSong()));
    connect(m_downPlayWidget->m_btnPrevSong, SIGNAL(clicked(bool)), this, SLOT(playPrevSong()));

    connect(m_downPlayWidget->m_btnPlayMode, SIGNAL(clicked()), this, SLOT(playmodeChanged()));


    connect(m_downVoiceWidget->m_btnMute, SIGNAL(clicked(bool)), this, SLOT(mute()));
    connect(m_downVoiceWidget->m_sliderVol, SIGNAL(valueChanged(int)), this, SLOT(changeVolVal(int)));


    connect(m_mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(onPositionChanged(qint64)));
    connect(m_mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));
    connect(m_downProgressBar->m_sliderPlayProgress, SIGNAL(valueChanged(int)), this, SLOT(changePlayProgress(int)));
    connect(m_downBtnPlayList->m_btnPlayList, SIGNAL(clicked(bool)), this, SLOT(showPlayList()));
    connect(m_showPlayList->m_PlayList, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(playChange()));
    connect(m_topSearchWidget->m_btnSearch, SIGNAL(clicked()), this, SLOT(searchSong()));

    connect(m_topSearchWidget->m_lineSearch, SIGNAL(returnPressed()), this, SLOT(searchSong()));


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateMusicWidget() {
    if (m_downPlayWidget->m_btnPlay->isChecked()) {
        //播放列表空否？
        if (!m_mediaPlayList->isEmpty()) {
            QStringList m_lyricList = m_lyricLoader.lyric();
            for(int i = 0; i< m_lyricList.size();++i)
            {
                QString tmp = m_lyricList.at(i);
                qDebug() << tmp;
                m_lyricWindow->setText(tmp);
            }
            m_lyricWindow->show();
            m_lyricWindow->setGeometry(this->rect().width()/2,this->rect().height()/2,100,100);
            m_mediaPlayer->play();
        }
    }

    else {
        m_lyricWindow->hide();
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


void MainWindow::setLeftWidget()
{
    m_leftWidget->setGeometry(0,69,250,661);
    QPalette pal(m_leftWidget->palette());
    pal.setColor(QPalette::Background,QColor(52,53,44));
    m_leftWidget->setAutoFillBackground(true);
    m_leftWidget->setPalette(pal);
    m_leftWidget->show();
}

void MainWindow::createFolder(QString folder) {
    QDir* newFolder = new QDir;
    bool exist = newFolder->exists(folder);

    if (exist) {
        //qDebug() << "This folder" << folder << "already exists" << endl;
    }
    else {
        newFolder->mkdir(folder);
        qDebug() << "folder making..";
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

void MainWindow::mousePressEvent(QMouseEvent *e) {
   // qDebug() << m_searchResult->pos();
    if (!isInRange(e->pos(), m_searchResult)
       &&!isInRange(e->pos(), m_topSearchWidget)) {
        m_searchResult->hide();
    }
}

bool MainWindow::isInRange(QPoint p, QWidget *widget) {
    if (p.x() <= widget->pos().x() + widget->width() && p.x() >= widget->pos().x()
      &&p.y() <= widget->pos().y() + widget->height() && p.y() >= widget->pos().y()) {
        return true;
    }
    return false;
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
    //qDebug() << "Hello" + strToSearch.toLatin1();
    m_searchResult->show();
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
            this->m_songArr = res["songs"].toArray();
            for (int i = 0; i < m_songArr.size(); i++) {
                auto objSong = m_songArr[i].toObject();
                auto id = getSongId(objSong);
                auto songName = objSong["name"].toString();
                auto artistName = getArtistName(objSong);
                strList.push_back(artistName + '-' + songName);
               // qDebug() << objSong["name"].toString() << artistName;
            }

            m_searchResult->setList(&strList);
            connect(m_searchResult, &QAbstractItemView::doubleClicked, this, &MainWindow::downloadSelectedSong, Qt::UniqueConnection);
            // ToDo: 下载完成后加入自动扫描到歌单的功能
        }
    }

}

void MainWindow::showMusicWidget() {
    m_leftMusicShowWidget->show();
    QPropertyAnimation *animation=new QPropertyAnimation(m_leftMusicShowWidget,"geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(0,730,1300,0));
    animation->setEndValue(QRect(0,69,1300,661));
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

void MainWindow::firstFinished() {

    connect(m_redirectedReply,&QNetworkReply::readyRead,this,&MainWindow::httpReadyRead);
    connect(m_redirectedReply,&QNetworkReply::downloadProgress,this,&MainWindow::updateDataReadProgress);
    connect(m_redirectedReply,&QNetworkReply::finished,this,&MainWindow::httpFinished);
}


void MainWindow::httpReadyRead() {
    if (m_curFile) {
        m_curFile->write(m_redirectedReply->readAll());
    }

}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes) {
    //qDebug() << bytesRead << "/" << totalBytes;
    m_downloadProgressBar->setMaximum(totalBytes);

    m_downloadProgressBar->setValue(bytesRead);
}

void MainWindow::httpFinished() {
    m_downloadProgressBar->hide();
    //qDebug() << "Downloaded" <<  m_curFile->size() << "bytes" ;
    if (m_curFile->size() > 1000) {
        if(m_database.insert(id, songName, artistName, filePath, albumName, lyricFileName))
        {
            QString name = songName + "-" + artistName;
            m_showPlayList->addSong(name);
            QString songdir = m_database.querySong(name);
            m_mediaPlayList->addMedia(QUrl::fromLocalFile(songdir));

        }
        disconnect(m_redirectedReply,&QNetworkReply::readyRead,this,&MainWindow::httpReadyRead);
        disconnect(m_redirectedReply,&QNetworkReply::downloadProgress,this,&MainWindow::updateDataReadProgress);
        disconnect(m_redirectedReply,&QNetworkReply::finished,this,&MainWindow::httpFinished);
    }

    if (m_curFile) {
        m_curFile->close();
        delete m_curFile;
        m_curFile = nullptr;
    }

    if(m_redirectedReply){
        delete m_redirectedReply;
    }
    m_redirectedReply = nullptr;
}

void MainWindow::downloadSelectedSong(const QModelIndex &index) {
    //这坨代码写的太屎了。。
    auto objSong = m_songArr[index.row()].toObject();
    //qDebug() << objSong.value("img1v1Url").toString();
    //qDebug() << objSong;
    auto strId = getSongId(objSong);
    id = strId;
    songName = objSong["name"].toString();
    artistName = getArtistName(objSong);
    qDebug() << strId;
    auto absPath = QApplication::applicationDirPath();
    auto dir = QApplication::applicationDirPath() + QString("/music/");
    createFolder(dir);
    m_curSongName = index.data().toString();
    filePath = dir + m_curSongName + ".mp3";
    //qDebug() << "FilePath:" << filePath;
    m_curFile = new QFile(filePath);
    m_curFile->open(QIODevice::WriteOnly);
    if (!m_curFile) {
        qDebug() << "文件打开失败";
        return;
    }
    m_accessManager = new QNetworkAccessManager(this);
    m_request = QNetworkRequest();

    auto link = QString("https://music.163.com/song/media/outer/url?id=" + strId);

    m_request.setUrl(link);
    m_reply = m_accessManager->get(m_request);
    m_downloadProgressBar->show();
    //m_downloadProgressBar->raise();
    m_searchResult->hide();

    //add music information to play list



    connect(m_reply,&QNetworkReply::finished,this,&MainWindow::urlRedirected);
    connect(m_reply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),          //异常
                this,&MainWindow::doProcessError);


    //download lyrics.
    auto lyricLink = QString("http://music.163.com/api/song/media?id=" + strId);
    auto acMgr = new QNetworkAccessManager();
    auto req =  QNetworkRequest();
    req.setUrl(lyricLink);
    m_lyricReply = acMgr->get(req);
    auto lyricPath = QApplication::applicationDirPath() + QString("/lyric/") ;
    lyricFileName = lyricPath + m_curSongName + ".txt";
    m_lyricFile = new QFile(lyricFileName);
    createFolder(lyricPath);



    QEventLoop loop;
    connect (m_lyricReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QByteArray array = m_lyricReply->readAll();
    QJsonParseError jsonErr;
    QJsonDocument json = QJsonDocument::fromJson(array, &jsonErr);
    auto obj = json.object();
    if (m_lyricFile->open(QIODevice::WriteOnly|QIODevice::Text)) {
        //m_lyricFile->write(array);

        QString strLyric = obj["lyric"].toString();
        QTextStream ts(m_lyricFile);
        ts.setCodec("utf-8");
        ts << strLyric << endl;
        m_lyricFile->close();
    }

    auto albumLink = QString("https://api.paugram.com/netease/?id=" + strId);
    req.setUrl(albumLink);
    m_albumReply = acMgr->get(req);
    QEventLoop albumLoop;
    connect (m_albumReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QByteArray albumArray = m_albumReply->readAll();

    QJsonDocument albumJson = QJsonDocument::fromJson(albumArray, &jsonErr);
    auto albumObj = albumJson.object();
    auto coverLink = albumObj.value("cover").toString();
    req.setUrl(coverLink);
    m_albumReply = acMgr->get(req);
    connect (m_albumReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    auto albumPath = QApplication::applicationDirPath() + QString("/album/") ;
    albumName = albumPath + m_curSongName + ".jpg";
    m_albumFile = new QFile(albumName);
    createFolder(albumPath);
    if (m_albumFile->open(QIODevice::WriteOnly)) {
        m_albumFile->write( m_albumReply->readAll());
        m_albumFile->close();
        qDebug() << "successfully downloaded the album cover.";
    }
}

void MainWindow::urlRedirected() {
    auto url = m_reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toString();

    m_redirectedRequest = QNetworkRequest();
    //qDebug() << url;
    m_redirectedRequest.setUrl(url);
    m_redirAccMgr = new QNetworkAccessManager(this);
    m_redirectedReply = m_redirAccMgr->get(m_redirectedRequest);
    connect(m_redirectedReply,&QNetworkReply::readyRead,this,&MainWindow::httpReadyRead);
    connect(m_redirectedReply,&QNetworkReply::downloadProgress,this,&MainWindow::updateDataReadProgress);
    connect(m_redirectedReply,&QNetworkReply::finished,this,&MainWindow::httpFinished);
    connect(m_redirectedReply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),          //异常
            this,&MainWindow::doProcessError);
    //connect(m_redirectedReply,&QNetworkReply::finished,this,&MainWindow::firstFinished);
}

void MainWindow::doProcessError(QNetworkReply::NetworkError code) {
    qDebug() << code;

}

void MainWindow::lyricRead() {
    m_lyricFile->write(m_lyricReply->readAll());
    qDebug() << "lyric loaded.";
}

void MainWindow::playmodeChanged() {
    m_playMode = (m_playMode + 1) % 3;
    qDebug() << m_playMode;
    if (m_playMode == 0) {
        m_mediaPlayList->setPlaybackMode(QMediaPlaylist::Sequential);

        m_downPlayWidget->m_btnPlayMode->setToolTip("顺序播放");
        m_downPlayWidget->m_btnPlayMode->setStyleSheet("QPushButton{border-image:url(:/images/images/comboxitem2.png)}");
        m_downPlayWidget->m_btnPlayMode->setGeometry(1120, 25, 30, 20);
    }

    else if (m_playMode == 1) {
        m_mediaPlayList->setPlaybackMode(QMediaPlaylist::Random);
        m_downPlayWidget->m_btnPlayMode->setToolTip("随机播放");
        m_downPlayWidget->m_btnPlayMode->setStyleSheet("QPushButton{border-image:url(:/images/images/comboxitem1.png)}");
        m_downPlayWidget->m_btnPlayMode->setGeometry(1120, 25, 30, 20);
    }

    else if (m_playMode == 2) {
        m_mediaPlayList->setPlaybackMode(QMediaPlaylist::Loop);
        m_downPlayWidget->m_btnPlayMode->setToolTip("单曲循环");
        m_downPlayWidget->m_btnPlayMode->setStyleSheet("QPushButton{border-image:url(:/images/images/comboxitem3.png)}");
        m_downPlayWidget->m_btnPlayMode->setGeometry(1120, 20, 35, 35);
    }
}

void MainWindow::playChange()
{
    int row = m_showPlayList->m_PlayList->currentIndex().row();
    QModelIndex index = m_showPlayList->m_PlayListModel->index(row,0);
    QString name = m_showPlayList->m_PlayListModel->data(index).toString();
    QString songdir = m_database.querySong(name);
    QString lyrdir = m_database.queryLyr(name);
    m_mediaPlayList->clear();
    m_mediaPlayList->addMedia(QUrl::fromLocalFile(songdir));
    qDebug() << m_lyricLoader.loadFromFile(lyrdir);

    //m_mediaPlayer->play();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setMaximumSize(1300, 800);
    setMinimumSize(1300, 800);
//    setWindowFlags(Qt::FramelessWindowHint|windowFlags());  //实现无边框
    //ui->btnPrevSong->setIcon(QIcon(QPixmap("D:/DSproj/MusicPlayer/images/IconPrevSong.ico")));
    root = "D:/DSproj/MusicPlayer";         //此处记得更改本地根目录
    //ui->setupUi(this);
    m_downWidget = new QWidget(this);
    setDownWidget(m_downWidget);
    m_downPlayWidget = new down_playWidget(m_downWidget);
    m_downPlayWidget->setGeometry(0,0,250,70);
//    setPrevIcon();
//    setNextIcon();
//    setPauseIcon();
//    setMuteIcon();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setDownWidget(QWidget *widget) {

    widget->setGeometry(0,730,1300,70);
    QPalette pal(widget->palette());
    pal.setColor(QPalette::Background,QColor(50,50,50));
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    widget->show();
}



//void MainWindow::setPrevIcon() {
//    QIcon prevIcon = QIcon(root + "/images/IconPrevSong.ico");
//    ui->btnPrevSong->setIcon(prevIcon);
//    ui->btnPrevSong->setFlat(true);
//}

//void MainWindow::setNextIcon() {
//    QIcon nextIcon = QIcon(root + "/images/IconNextSong.jpg");
//    ui->btnNextSong->setIcon(nextIcon);
//    ui->btnNextSong->setFlat(true);
//}

//void MainWindow::setPauseIcon() {
//    QIcon pauseIcon = QIcon(root + "/images/pause.jpg");
//    ui->btnPause->setIcon(pauseIcon);
//    ui->btnPause->setFlat(true);
//}

//void MainWindow::setMuteIcon() {
//    QIcon muteIcon = QIcon(root + "/images/mute.jpg");
//    ui->btnMute->setIcon(muteIcon);
//    ui->btnMute->setFlat(true);

//}

#include "down_playwidget.h"

Down_PlayWidget::Down_PlayWidget(QWidget *parent) :QWidget(parent) {
    // m_btnPlay的初始化
    // 是否可以绑定空格键?
    m_btnPlay = new QPushButton(this);              //new 对象
    //m_btnPlay->setFlat(true);                       //设置无边框
    m_btnPlay->setCursor(Qt::PointingHandCursor);   //设置指针
    m_btnPlay->setToolTip("播放");                   //设置鼠标悬停提示
    m_btnPlay->setGeometry(100,10,50,50);           //从(100, 10)开始，显示大小为(50, 50)的按钮
    m_btnPlay->setCheckable(true);                  //checked状态
    m_btnPlay->setChecked(false);                   //设置checked
    m_btnPlay->setStyleSheet("QPushButton:checked{border-image:url(:/images/images/pause.png)}\
                              QPushButton:!checked{border-image:url(:/images/images/play_pressed.png)}");
                             //用qrc实现资源索引

    // m_btnPrevSong的初始化
    m_btnPrevSong = new QPushButton(this);
    m_btnPrevSong->setCursor(Qt::PointingHandCursor);   //设置指针
    m_btnPrevSong->setToolTip("上一曲");                 //设置鼠标悬停提示
    m_btnPrevSong->setGeometry(30, 15 ,40, 40);
    m_btnPrevSong->setStyleSheet("QPushButton{border-image:url(:/images/images/before.png)}\
                              QPushButton:hover{border-image:url(:/images/images/before_pressed.png)}");


    // m_btnNextSong的初始化，同上
    m_btnNextSong = new QPushButton(this);
    m_btnNextSong->setCursor(Qt::PointingHandCursor);   //设置指针
    m_btnNextSong->setToolTip("下一曲");                 //设置鼠标悬停提示
    m_btnNextSong->setGeometry(180, 15 ,40, 40);
    m_btnNextSong->setStyleSheet("QPushButton{border-image:url(:/images/images/next_normal.png)}\
                                  QPushButton:hover{border-image:url(:/images/images/next_pressed.png)}");


}

void Down_PlayWidget::setMediaPlayer(QMediaPlayer* m) {
    m_mediaPlayer = m;
}

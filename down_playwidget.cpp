#include "down_playwidget.h"

down_playWidget::down_playWidget(QWidget *parent) :QWidget(parent){
    // m_btnPlay的初始化
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



}

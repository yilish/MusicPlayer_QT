#include "down_playlistbutton.h"


Down_PlayListButton::Down_PlayListButton(QWidget *parent) : QWidget(parent)
{

    //设置播放列表按钮
    m_btnPlayList = new QPushButton(this);
    m_btnPlayList->setGeometry(20, 25, 20, 20);
    m_btnPlayList->setToolTip(QString("播放列表"));
    m_btnPlayList->setCursor(Qt::PointingHandCursor);
    m_btnPlayList->setCheckable(true);
    m_btnPlayList->setChecked(false);
    m_btnPlayList->setStyleSheet("QPushButton:checked{border-image:url(:/images/images/list_normal.png)}\
                              QPushButton:!checked{border-image:url(:/images/images/list_pressed.png)}");



}

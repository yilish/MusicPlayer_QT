#include "down_playprogressbar.h"


Down_PlayProgressBar::Down_PlayProgressBar(QWidget *parent)
    :QWidget(parent),
      m_bar(this),
      m_value(this),
      m_slider(this)
{
    m_slider.setMaximum(100);
    //应该先添加歌曲的信息
    m_slider.setMinimum(0);
    m_slider.setValue(0);
    m_slider.setOrientation(Qt::Horizontal);


}

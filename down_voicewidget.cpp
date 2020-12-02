#include "down_voicewidget.h"



Down_VoiceWidget::Down_VoiceWidget(QWidget *parent)
    :QWidget(parent)
{
    m_btnMute = new QPushButton(this);

    m_btnMute->setGeometry(20, 25, 20, 20);
    m_btnMute->setToolTip(QString("音量"));
    m_btnMute->setCursor(Qt::PointingHandCursor);
    m_btnMute->setCheckable(true);
    m_btnMute->setChecked(false);
    m_btnMute->setStyleSheet("QPushButton:checked{border-image:url(:/images/images/voice_unclicked.png)}\
                              QPushButton:!checked{border-image:url(:/images/images/voice_clicked.png)}");

}

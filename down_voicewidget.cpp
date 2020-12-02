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



    m_sliderVol = new MySlider(this);
    m_sliderVol->setOrientation(Qt::Horizontal);
    m_sliderVol->setGeometry(50,32,100,8);
    m_sliderVol->setMinimum(0);
    m_sliderVol->setMaximum(100);
    m_sliderVol->setSingleStep(10);
    m_sliderVol->setPageStep(10);
    m_sliderVol->setValue(30);
    m_sliderVol->setCursor(Qt::PointingHandCursor);
    QFile* qssFile = new QFile(":/qss/sliderVolStyle.qss");
    QSSParser* parseFile = new QSSParser(qssFile);
    auto strStyle = parseFile->getStyleSheet();

    m_sliderVol->setStyleSheet(strStyle);
}

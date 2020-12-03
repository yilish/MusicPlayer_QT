#ifndef DOWN_VOICEWIDGET_H
#define DOWN_VOICEWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPushButton>
#include <QSlider>
#include "myslider.h"
#include "qssparser.h"

class Down_VoiceWidget: public QWidget
{
public:
    explicit Down_VoiceWidget(QWidget* parent = 0);
    QPushButton* m_btnMute;
    QSlider* m_sliderVol;


};

#endif // DOWN_VOICEWIDGET_H

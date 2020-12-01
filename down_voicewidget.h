#ifndef DOWN_VOICEWIDGET_H
#define DOWN_VOICEWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPushButton>
class Down_VoiceWidget: public QWidget
{
public:
    explicit Down_VoiceWidget(QWidget* parent = 0);
    QPushButton* m_btnMute;

};

#endif // DOWN_VOICEWIDGET_H

#ifndef DOWN_PLAYPROGRESSBAR_H
#define DOWN_PLAYPROGRESSBAR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QSlider>

class Down_PlayProgressBar :public QWidget
{
    Q_OBJECT
public:
    explicit Down_PlayProgressBar(QWidget* parent);
    QProgressBar m_bar;
    QLabel m_value;
    QSlider m_slider;

public slots:
    //void onValueChanged(int value);
};

#endif // DOWN_PLAYPROGRESSBAR_H

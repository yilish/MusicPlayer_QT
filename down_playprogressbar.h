#ifndef DOWN_PLAYPROGRESSBAR_H
#define DOWN_PLAYPROGRESSBAR_H
#pragma once
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QSlider>
#include <myslider.h>
#include "qssparser.h"

class Down_PlayProgressBar :public QWidget
{
    Q_OBJECT
public:
    explicit Down_PlayProgressBar(QWidget* parent);
    MySlider* m_sliderPlayProgress;
    QLabel* m_lblLeft;
    QLabel* m_lblRight;
public slots:
    //void onValueChanged(int value);
};

#endif // DOWN_PLAYPROGRESSBAR_H

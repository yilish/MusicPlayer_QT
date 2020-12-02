#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QObject>
#include <QWidget>
#include <QSlider>
#include <QMouseEvent>

class MySlider: public QSlider
{
    Q_OBJECT
public:
    MySlider(QWidget* parent = nullptr) : QSlider(parent) {};

    void mousePressEvent(QMouseEvent *ev) override;
};

#endif // MYSLIDER_H

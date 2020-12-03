#include "myslider.h"




void MySlider::mousePressEvent(QMouseEvent *ev) {
    auto curX = ev->pos().x();
    double per = curX * 1.0 / this->width();

    int val = per * (this->maximum() - this->minimum()) + this->minimum();

    this->setValue(val);

    QSlider::mousePressEvent(ev);
}

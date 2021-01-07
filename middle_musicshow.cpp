#include "middle_musicshow.h"



Middle_musicShow::Middle_musicShow(QWidget *parent) {
    setParent(parent);
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background,QColor(255,230,250));
    setAutoFillBackground(true);
    setPalette(pal);
    show();

    QPixmap pix;
    pix.load(":/images/TJnight.png");
    m_lblImage = new QLabel(this);
    m_lblImage->setPixmap(pix.scaled(1050, 661, Qt::KeepAspectRatioByExpanding));
    m_lblImage->setGeometry(0,0,1050,661);

}

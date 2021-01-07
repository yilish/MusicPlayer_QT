#include "middle_wheelpic.h"



Middle_WheelPic::Middle_WheelPic(QWidget *parent)
{
    setParent(parent);
    auto curDir = "D:/DSproj/build-MusicPlayer-Desktop_Qt_5_12_9_MinGW_64_bit-Debug/debug/album/";

    m_lblPrevPrev = new QLabel(this);

    m_lblPrevPrev->setPixmap(curDir + QString("陈雪凝-你的酒馆对我打了烊.jpg"));
    QSize sz(400, 400);
    m_lblPrevPrev->setPixmap(m_lblPrevPrev->pixmap()->scaled(sz, Qt::KeepAspectRatio));
    m_lblPrevPrev->setGeometry(0, 3*58, 400, 400);
    //m_imgPrev.load(curDir + QString("陈雪凝-你的酒馆对我打了烊.jpg"));
    m_lblPrev = new QLabel(this);

    m_lblPrev->setPixmap(curDir + QString(u8"倪莫问-众生皆苦（翻自 白智英） .jpg"));
    //QSize sz(400, 400);
    m_lblPrev->setPixmap(m_lblPrev->pixmap()->scaled(sz, Qt::KeepAspectRatio));
    m_lblPrev->setGeometry(58*2, 58*1.5, 400, 400);
    m_lblPrev->lower();
    m_lblPrevPrev->lower();


    m_lblCur = new QLabel(this);
    QPixmap curPix(":/images/tjjd1.png");
    m_lblCur->setPixmap(curPix);
    //QSize sz(400, 400);
    m_lblCur->setPixmap(m_lblCur->pixmap()->scaled(sz, Qt::KeepAspectRatio));
    m_lblCur->setGeometry(4*58, 0, 400, 400);

}






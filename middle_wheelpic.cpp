#include "middle_wheelpic.h"



Middle_WheelPic::Middle_WheelPic(QWidget *parent)
{
    setParent(parent);
    auto curDir = "D:/DSproj/build-MusicPlayer-Desktop_Qt_5_12_9_MinGW_64_bit-Debug/debug/album/";
    m_pixCur.load(curDir + QString("陈雪凝-你的酒馆对我打了烊.jpg"));
    m_pixNext.load(curDir + QString(u8"倪莫问-众生皆苦（翻自 白智英） .jpg"));
    QLabel* lbl1 = new QLabel(this);

    lbl1->setPixmap(curDir + QString("陈雪凝-你的酒馆对我打了烊.jpg"));
    QSize sz(400, 400);
    lbl1->setPixmap(lbl1->pixmap()->scaled(sz, Qt::KeepAspectRatio));
    lbl1->setGeometry(100, 0, 400, 400);
    //m_imgPrev.load(curDir + QString("陈雪凝-你的酒馆对我打了烊.jpg"));
    QLabel* lbl2 = new QLabel(this);

    lbl2->setPixmap(curDir + QString(u8"倪莫问-众生皆苦（翻自 白智英） .jpg"));
    //QSize sz(400, 400);
    lbl2->setPixmap(lbl2->pixmap()->scaled(sz, Qt::KeepAspectRatio));
    lbl2->setGeometry(200, 0, 400, 400);


    QLabel* lbl3 = new QLabel(this);

    lbl3->setPixmap(curDir + QString(u8"蔡依林-倒带.jpg"));
    //QSize sz(400, 400);
    lbl3->setPixmap(lbl3->pixmap()->scaled(sz, Qt::KeepAspectRatio));
    lbl3->setGeometry(0, 0, 400, 400);
    lbl3->lower();
}






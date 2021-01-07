#ifndef MIDDLE_WHEELPIC_H
#define MIDDLE_WHEELPIC_H

#include <QWidget>
#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include <QStyleOption>
#include <QLabel>
class MainPageAlbumCover : public QLabel {
public:
    MainPageAlbumCover(QWidget* parent);
    QPixmap m_pix;
    void paintEvent(QPaintEvent *event);
};

class Middle_WheelPic : public QWidget
{
public:
    Middle_WheelPic(QWidget* parent);
    //void paintEvent(QPaintEvent *event);
    QLabel* m_lblCur;
    QLabel* m_lblPrev;
    QLabel* m_lblPrevPrev;
    //QImage m_imgPrev;
};

#endif // MIDDLE_WHEELPIC_H

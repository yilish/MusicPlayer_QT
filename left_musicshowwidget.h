#ifndef LEFT_MUSICSHOWWIDGET_H
#define LEFT_MUSICSHOWWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QPushButton>
#include <QTimer>
#include <QLabel>
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QBitmap>
#include <QDebug>
#include <QFile>
#include <database.h>
#include "song.h"

class Left_musicShowWidget: public QWidget
{
    Q_OBJECT;
public:
    Left_musicShowWidget(QWidget* parent);
    void paintEvent(QPaintEvent *event) ;
    void setSong(Song* song);
    QColor m_color;
    QPushButton* m_btnLess;
    QTimer* m_tmrUpdate;
    QTimer* m_tmrUpdateNew;
    QLabel* m_lblSong;
    QLabel* m_lblAlbum;
    QLabel* m_lblArtist;
    QPixmap m_albumCover;
    double i = 0;
    int j = 0;
public slots:
    void minimumWidget();
    void updateAlbum();
    void updateStick();
};

#endif // LEFT_MUSICSHOWWIDGET_H

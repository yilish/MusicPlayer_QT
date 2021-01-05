#ifndef LEFT_MUSICBUTTON_H
#define LEFT_MUSICBUTTON_H
#include <QPushButton>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QTimer>
#include <QFont>
#include <QPalette>
#include <QColor>

class Left_MusicButton : public QPushButton
{
public:
    Left_MusicButton(QWidget* parent);
    QLabel m_lblAlbumCover;//歌曲封面
    QPixmap m_pix;
    QLabel *m_lblMusicName;//歌曲名称
private:
    void paintEvent(QPaintEvent *event);
};

#endif // LEFT_MUSICBUTTON_H

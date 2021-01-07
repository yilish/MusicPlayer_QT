#include "left_musicbutton.h"

Left_MusicButton::Left_MusicButton(QWidget* parent)
{
    setParent(parent);
    m_lblMusicName = new QLabel(this);
    QPalette pal1;
    pal1.setColor(QPalette::ButtonText,QColor(255,255,255));
    QFont font("Courier",12);
    setCursor(Qt::PointingHandCursor);
    m_pix = QPixmap(":/images/txy.png");
    m_lblMusicName->setGeometry(70,10,150,40);
    m_lblMusicName->setFont(font);
    m_lblMusicName->setText(tr("同心云音乐"));
    m_lblMusicName->setPalette(pal1);
    setPalette(pal1);
}

void Left_MusicButton::setSong(Song *song)
{
    m_lblMusicName->setText(song->getName());
    m_pix.load(song->getImageUrl());
}

void Left_MusicButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();
    QRectF rect=QRectF(0,0,250,64);
    QColor color(73,90,128);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.drawRect(rect);
    painter.restore();
    painter.save();
    painter.drawPixmap(0,0,64,64,m_pix);
    painter.restore();
}

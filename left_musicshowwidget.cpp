#include "left_musicshowwidget.h"


Left_musicShowWidget::Left_musicShowWidget(QWidget *parent) {
    setParent(parent);
    this->hide();
    QPalette pal;
    m_color = QColor(43,43,43);
    m_color.setAlphaF(1);
    pal.setColor(QPalette::Background,m_color);
    setAutoFillBackground(true);
    setPalette(pal);
    show();
    m_btnLess = new QPushButton(this);
    m_btnLess->setGeometry(1220,20,30,30);
    m_btnLess->setStyleSheet("QPushButton{border:0px;border-image:url(:/images/images/less.png)}\
                                                 QPushButton:hover{background:rgb(100,100,100)}");
    connect(m_btnLess,SIGNAL(clicked(bool)),this,SLOT(minimumWidget()));
    m_tmrUpdate = new QTimer(this);
    m_tmrUpdate->setInterval(25);
    connect(m_tmrUpdate,SIGNAL(timeout()),this,SLOT(updateAlbum()));
    m_tmrUpdateNew = new QTimer(this);
    m_tmrUpdateNew->setInterval(15);
    connect(m_tmrUpdateNew, SIGNAL(timeout()),this,SLOT(updateStick()));

    m_lblSong = new QLabel(this);
    m_lblArtist = new QLabel(this);
    m_lblAlbum = new QLabel(this);
    QPalette pal0;
    pal0.setColor(QPalette::WindowText,QColor(255,250,200));
    QFont font0("微软雅黑",14);
    QFont font1("微软雅黑",10);
    m_lblSong->setFont(font0);
    m_lblSong->setPalette(pal0);
    m_lblArtist->setFont(font1);
    m_lblArtist->setPalette(pal0);
    m_lblAlbum->setFont(font1);
    m_lblAlbum->setPalette(pal0);
    m_lblSong->setText("网易云音乐");
    m_lblSong->setGeometry(650,75,300,45);

    //m_lblSong->setFont(songFt);
    m_lblArtist->setText("歌手");
    m_lblArtist->setGeometry(650,130,80,35);
    m_lblSong->show();
    m_lblAlbum->setText("专辑");
    m_lblAlbum->setGeometry(780,130,300,35);
    m_lblAlbum->show();

}
QPixmap PixmapToRound(QPixmap &src, int radius)
{
    if (src.isNull()) {
        return QPixmap();
    }

    QSize size(2*radius, 2*radius);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 99, 99);

    QPixmap image = src.scaled(size);
    image.setMask(mask);
    return image;
}
void Left_musicShowWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();
    auto pix2 = QPixmap(":/images/images/greybgc.png");
    painter.drawPixmap(0,0,1300,661,pix2);
    painter.restore();
    painter.save();
    QRectF rect=QRectF(0,0,1300,661);
    QColor color1(43,43,43);
    color1.setAlphaF(0.9);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color1);
    painter.drawRect(rect);
    painter.restore();
    painter.save();
    QColor m_color(100,100,100);
    painter.translate(85,110);
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_color);
    painter.drawEllipse(-5,-5,400,400);
    painter.restore();
    QPixmap pix1;
    pix1.load(":/images/images/heijiaopian.png");
    painter.save();
    painter.translate(85,110);
    painter.translate(195,195);
    painter.rotate(i);
    painter.translate(-195,-195);
    painter.drawPixmap(0,0,390,390,pix1);
    painter.restore();
    QPixmap pix;
    pix.load(":/images/images/changegan.png");
    painter.save();
    painter.translate(30,-200);
    painter.translate(250,250);
    painter.rotate(j);
    painter.translate(-250,-250);
    painter.drawPixmap(0,0,500,500,pix);
    painter.restore();


    painter.save();
    painter.translate(173, 205);
    painter.translate(110,110);
    painter.rotate(i++);
    painter.translate(-110,-110);
    if (!m_albumCover.isNull()) {
        painter.drawPixmap(0,0,220,220, m_albumCover);
    }
    painter.restore();
}

void Left_musicShowWidget::setSong(Song *song)
{
    this->m_lblArtist->setText(song->getNameArtist());
    this->m_lblAlbum->setText(song->getAlbumName());
    this->m_lblSong->setText(song->getName());
    qDebug() << song->getImageUrl();
    if (m_albumCover.load(song->getImageUrl())) {
        qDebug() << "successfully loaded this new pix.";
        m_albumCover = PixmapToRound(m_albumCover, 110);


    }
    else {
        qDebug() << "loading failed.";
    }


}

void Left_musicShowWidget::minimumWidget() {
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(700);
    //animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->setStartValue(QRect(0,69,1300,661));
    animation->setEndValue(QRect(0,730,0,0));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    if(!animation->duration()) {
        this->hide();
    }
}

void Left_musicShowWidget::updateAlbum() {
    i = (i + 1) % 360;
    update();
}

void Left_musicShowWidget::updateStick() {
    if (j++ > 30) {
        m_tmrUpdateNew->stop();
    }
    update();
}

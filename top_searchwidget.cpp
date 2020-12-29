#include "top_searchwidget.h"

Top_SearchWidget::Top_SearchWidget(QWidget* parent):
    QWidget(parent)
{
    QPalette pal;
    pal.setColor(QPalette::Text, QColor(100, 100, 100));

    m_lineSearch = new QLineEdit(this);
    m_lineSearch->setGeometry(15, 0, 300, 30);
    QFile* file = new QFile(":/qss/lineSearchStyle.qss");
    QSSParser qss(file);
    auto str = qss.getStyleSheet();
    m_lineSearch->setStyleSheet(str);
    m_lineSearch->setPlaceholderText(QString("搜索音乐,歌手,歌词,用户"));

    m_lineSearch->setPalette(pal);
    m_btnSearch = new QPushButton(this);
    m_btnSearch->setGeometry(315,0,30,30);
    m_btnSearch->setToolTip(QString("搜索"));
    m_btnSearch->setStyleSheet("QPushButton{background:rgb(0,20,20);border:0px;}\
                                QPushButton{image:url(:/images/images/search_normal.png)}\
                                QPushButton:hover{image:url(:/images/images/search_press.png)}\
                                QPushButton:pressed{image:url(:/images/images/search_normal.png)}");
    m_btnSearch->setCursor(Qt::PointingHandCursor);




}

void Top_SearchWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor color(0,20,20);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    QRectF rect=QRectF(0,0,360,30);
    painter.drawRoundedRect(rect,15,15);
    painter.restore();
}

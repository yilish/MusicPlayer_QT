#include "down_playprogressbar.h"


Down_PlayProgressBar::Down_PlayProgressBar(QWidget *parent)
    :QWidget(parent) {
    m_sliderPlayProgress = new MySlider(this);
    m_sliderPlayProgress->setOrientation(Qt::Horizontal);
    m_sliderPlayProgress->setGeometry(55,22,550,30);
    m_sliderPlayProgress->setMinimum(0);
    m_sliderPlayProgress->setMaximum(100);
    m_sliderPlayProgress->setSingleStep(1);
    m_sliderPlayProgress->setPageStep(1);
    m_sliderPlayProgress->setCursor(Qt::PointingHandCursor);

    QFile* qssFile = new QFile(":/qss/sliderVolStyle.qss");
    QSSParser* parseFile = new QSSParser(qssFile);
    auto strStyle = parseFile->getStyleSheet();

    m_sliderPlayProgress->setStyleSheet(strStyle);
    QPalette pal;
    pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
    QFont font("Courier", 8);
    //为什么显示不出来？
    m_lblLeft = new QLabel(this);
    m_lblLeft->setAlignment(Qt::AlignCenter);
    m_lblLeft->setGeometry(0, 12, 50, 50);
    m_lblLeft->setFont(font);
    m_lblLeft->setPalette(pal);

    m_lblRight = new QLabel(this);
    m_lblRight->setAlignment(Qt::AlignCenter);
    m_lblRight->setGeometry(613, 12, 50, 50);
    m_lblRight->setFont(font);
    m_lblRight->setPalette(pal);
    m_lblRight->setText(QString("0:00"));
    m_lblLeft->setText(QString("0:00"));
}


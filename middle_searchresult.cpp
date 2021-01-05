#include "middle_searchresult.h"

Middle_searchResult::Middle_searchResult(QWidget *parent) {
    setParent(parent);
    m_itemModel = new QStandardItemModel(this);

    QFile* qssFile = new QFile((":/qss/searchListStyle.qss"));

    QSSParser parser(qssFile);
    setStyle(new SearchBoxProxyStyle);
    this->setStyleSheet(parser.getStyleSheet());
    QPalette pal = palette();
    //pal.setColor(QPalette::Background, QColor(52,53,44,100));

    this->setAutoFillBackground(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setPalette(pal);
    //setAttribute(Qt::WA_TranslucentBackground);
    this->setFixedSize(360, 360);
    //this->reset();
    setFrameShape(QFrame::NoFrame);
}



void Middle_searchResult::setList(QStringList *strList)
{
    m_strList = strList;
    m_itemModel->clear();
    for (int i = 0; i < strList->size(); i++) {
        QString string = static_cast<QString>(strList->at(i));
        QStandardItem *item = new QStandardItem(string);
        //item->setFont(QFont( "Times", 10, qRgb(214, 214, 214) ));
        item->setForeground(QBrush(QColor(214, 214, 214)));

        m_itemModel->appendRow(item);
    }

    this->setModel(this->m_itemModel);


    //QPalette pal;

//    pal.setColor(QPalette::Background, QColor(54, 54, 54));

//    this->setPalette(pal);


}

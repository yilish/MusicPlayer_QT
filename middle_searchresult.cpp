#include "middle_searchresult.h"

Middle_searchResult::Middle_searchResult(QWidget *parent)
{
    setParent(parent);
    m_itemModel = new QStandardItemModel(this);
    this->setStyleSheet("background-color: #303030");
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(255,0,0,200));
    setPalette(pal);
    this->setFixedSize(360, 400);
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

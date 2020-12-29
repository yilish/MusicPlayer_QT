#include "middle_searchresult.h"

Middle_searchResult::Middle_searchResult(QWidget *parent)
{
    setParent(parent);
    m_itemModel = new QStandardItemModel(this);

}

void Middle_searchResult::setList(QStringList *strList)
{
    m_strList = strList;
    m_itemModel->clear();
    for (int i = 0; i < strList->size(); i++) {
        QString string = static_cast<QString>(strList->at(i));
        QStandardItem *item = new QStandardItem(string);
        m_itemModel->appendRow(item);
    }

    this->setModel(this->m_itemModel);
    this->setFixedSize(360, 500);
}

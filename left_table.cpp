#include "left_table.h"


Left_Table::Left_Table(QWidget *parent) : QWidget(parent)
{
    //设置左侧菜单格式
    m_LeftTableModel = new QStandardItemModel;
    m_LeftTableModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("我的音乐")));
    m_LeftTableModel->setItem(0, 0, new QStandardItem("本地音乐"));

    //设置左侧菜单
    m_LeftTable = new QTableView(this);
    m_LeftTable->setGeometry(0, 65, 300, 700);
    m_LeftTable->setModel(m_LeftTableModel);
    m_LeftTable->verticalHeader()->hide();
    //m_LeftTable->horizontalHeader()->hide();
    m_LeftTable->setColumnWidth(0, 300);
    m_LeftTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_LeftTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_LeftTable->setAlternatingRowColors(true);
}

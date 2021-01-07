#include "left_table.h"


Left_Table::Left_Table(QWidget *parent) : QWidget(parent)
{
    //设置左侧菜单格式
    m_LeftTableModel = new QStandardItemModel;
    m_LeftTableModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("我的音乐")));
    //m_LeftTableModel->setItem(1, 0, new QStandardItem(QObject::tr("               创建的歌单")));

    //设置左侧菜单
    m_LeftTable = new QTableView(this);
    m_LeftTable->setGeometry(0, 65, 250, 665);
    m_LeftTable->setModel(m_LeftTableModel);
    m_LeftTable->verticalHeader()->hide();
    //m_LeftTable->horizontalHeader()->hide();
    m_LeftTable->setColumnWidth(0, 250);
    m_LeftTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_LeftTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_LeftTable->setAlternatingRowColors(true);
    m_LeftTable->horizontalHeader()->setDisabled(true);
    //tableWidget->horizontalHeader()->setDisabled(true);
    m_LeftTable->setStyleSheet("background-color:rgba(51,51,51);\
                                ");
    m_LeftTable->setFocusPolicy(Qt::NoFocus);
    m_LeftTable->setFrameShape(QFrame::NoFrame);
    m_LeftTable->horizontalHeader()->setStyleSheet("QHeaderView::section {border:none;font-size: 30px;"
                                                                       "color: rgb(214, 214, 214);background-color: rgb(51, 51, 51)}");

}

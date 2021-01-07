#include "down_playlist.h"
#include <QPalette>
Down_PlayList::Down_PlayList(QWidget *parent) : QWidget(parent)
{
    this->hide();

    //设置播放列表格式
    m_PlayListModel = new QStandardItemModel;
    m_PlayListModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("歌曲列表")));
    m_PlayListModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("")));
    //m_PlayListModel->horizontalHeaderItem(0)->setBackground(QBrush(QColor(255, 0, 0)));
    //m_PlayListModel->horizontalHeaderItem(1)->setBackground(QBrush(QColor(255, 0, 0)));
    m_PlayListModel->setColumnCount(2);
    //m_PlayListModel->setItem(0, 0, new QStandardItem("1"));
    //m_PlayListModel->setItem(1, 0, new QStandardItem("2"));

    //设置播放列表
    m_PlayList = new QTableView(this);
    m_PlayList->setGeometry(100, 65, 400, 700);
    m_PlayList->setModel(m_PlayListModel);
    m_PlayList->verticalHeader()->hide();
    m_PlayList->setColumnWidth(0, 340);
    m_PlayList->setColumnWidth(1, 50);
    m_PlayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_PlayList->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_PlayList->setAlternatingRowColors(true);
    m_PlayList->setStyleSheet("background-color:grey");

    m_PlayList->horizontalHeader()->setDisabled(true);
}

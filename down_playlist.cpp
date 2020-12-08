#include "down_playlist.h"

Down_PlayList::Down_PlayList(QWidget *parent) : QWidget(parent)
{
    this->hide();

    //设置播放列表格式
    m_PlayListModel = new QStandardItemModel;
    m_PlayListModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("歌曲列表")));
    m_PlayListModel->setItem(0, 0, new QStandardItem("1"));
    m_PlayListModel->setItem(1, 0, new QStandardItem("2"));

    //设置播放列表
    m_PlayList = new QTableView(this);
    m_PlayList->setGeometry(0, 0, 500, 730);
    m_PlayList->setModel(m_PlayListModel);
    m_PlayList->verticalHeader()->hide();
    m_PlayList->setColumnWidth(0, 500);
    m_PlayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_PlayList->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_PlayList->setAlternatingRowColors(true);

}

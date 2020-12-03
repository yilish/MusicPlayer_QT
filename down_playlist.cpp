#include "down_playlist.h"

Down_PlayList::Down_PlayList(QWidget *parent) : QWidget(parent)
{
    this->hide();

    //设置播放列表格式
    m_PlayListModel = new QStandardItemModel;
    m_PlayListModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("歌曲列表")));

    //设置播放列表
    m_PlayList = new QTableView(this);
    m_PlayList->setGeometry(500,220,800,490);
    m_PlayList->setModel(m_PlayListModel);
    m_PlayList->verticalHeader()->hide();
    m_PlayList->setColumnWidth(0, 800);
    m_PlayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_PlayList->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_PlayList->setAlternatingRowColors(true);
}

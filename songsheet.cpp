#include "songsheet.h"

SongSheet::SongSheet(QWidget *parent) : QWidget(parent)
{
    this->hide();

    //设置播放列表格式
    m_SongSheetModel = new QStandardItemModel;
    m_SongSheetModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("")));
    m_SongSheetModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("音乐标题")));
    m_SongSheetModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("歌手")));
    m_SongSheetModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("专辑")));
    m_SongSheetModel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("")));
    m_SongSheetModel->setColumnCount(5);
    //m_PlayListModel->setItem(0, 0, new QStandardItem("1"));
    //m_PlayListModel->setItem(1, 0, new QStandardItem("2"));

    //设置播放列表
    m_SongSheet = new QTableView(this);
    m_SongSheet->setGeometry(0, 161, 1050, 500);
    m_SongSheet->setModel(m_SongSheetModel);
    m_SongSheet->verticalHeader()->hide();
    m_SongSheet->setColumnWidth(0, 50);
    m_SongSheet->setColumnWidth(1, 450);
    m_SongSheet->setColumnWidth(2, 240);
    m_SongSheet->setColumnWidth(3, 240);
    m_SongSheet->setColumnWidth(4, 50);
    m_SongSheet->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_SongSheet->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_SongSheet->setAlternatingRowColors(true);
    m_SongSheet->setStyleSheet("background-color:gray");

    m_SongSheet->horizontalHeader()->setDisabled(true);
}

void SongSheet::Show()
{
    this->setGeometry(250,69,1050,661);
    this->show();
}

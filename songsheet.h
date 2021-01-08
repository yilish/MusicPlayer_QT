#ifndef SONGSHEET_H
#define SONGSHEET_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QStandardItemModel>
#include <QTableView>
#include <QStringListIterator>
#include <QFileDialog>
#include <QDir>
#include <QDirModel>
#include <QMediaPlaylist>
#include <QHeaderView>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include "song.h"
class SongSheet: public QWidget
{
    Q_OBJECT
public:
    SongSheet(QWidget *parent = 0);
    QTableView *m_SongSheet;
    QStandardItemModel *m_SongSheetModel;
    bool addSong(Song s)
    {
        int row=m_SongSheetModel->rowCount();
        QString r = QString::number(row + 1);
        m_SongSheetModel->setItem(row, 0, new QStandardItem(r));
        m_SongSheetModel->setItem(row, 1, new QStandardItem(""));
        m_SongSheetModel->setItem(row, 2, new QStandardItem(s.getName()));
        m_SongSheetModel->setItem(row, 3, new QStandardItem(s.getArtist()));
        m_SongSheetModel->setItem(row, 4, new QStandardItem(s.getAlbumName()));
        m_SongSheetModel->setItem(row, 5, new QStandardItem("X"));
        for (int i = 0; i < 6; i++) {
            m_SongSheetModel->item(row, i)->setBackground(QColor(43,43,43));
            m_SongSheetModel->item(row, i)->setForeground(QColor(213,207,177));
            auto ft = m_SongSheetModel->item(row, i)->font();
            ft.setFamily("Microsoft yahei");

            m_SongSheetModel->item(row, i)->setFont(ft);

        }
        return true;
    }
    bool addLocalSong(Song s)
    {
        int row=m_SongSheetModel->rowCount();
        QString r = QString::number(row + 1);
        m_SongSheetModel->setItem(row, 0, new QStandardItem(r));
        m_SongSheetModel->setItem(row, 1, new QStandardItem(""));
        m_SongSheetModel->setItem(row, 2, new QStandardItem(s.getName()));
        m_SongSheetModel->setItem(row, 3, new QStandardItem(s.getArtist()));
        m_SongSheetModel->setItem(row, 4, new QStandardItem(s.getAlbumName()));
        m_SongSheetModel->setItem(row, 5, new QStandardItem("+"));
        for (int i = 0; i < 6; i++) {
            m_SongSheetModel->item(row, i)->setBackground(QColor(43,43,43));
            m_SongSheetModel->item(row, i)->setForeground(QColor(213,207,177));
            auto ft = m_SongSheetModel->item(row, i)->font();
            ft.setFamily("Microsoft yahei");
            m_SongSheetModel->item(row, i)->setFont(ft);
        }
        return true;
    }
    void Show();
    QString name;
    void SortByColumnSlot(int column)
    {
        static bool bStata = true;
        m_SongSheet->sortByColumn(column, bStata ? Qt::AscendingOrder : Qt::DescendingOrder);
        bStata = !bStata;
    }
};

#endif // SONGSHEET_H

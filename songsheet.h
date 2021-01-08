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
#include <QLabel>
#include "top_searchwidget.h"
class SongSheet: public QWidget
{
    Q_OBJECT
public:
    SongSheet(QWidget *parent = 0);
    QTableView *m_SongSheet;
    QStandardItemModel *m_SongSheetModel;
    QLabel* m_cover;
    QLabel* sname;
    Top_SearchWidget* search;
    bool addSong(Song s)
    {
        int row=m_SongSheetModel->rowCount();
        QString r = QString::number(row + 1);
        m_SongSheetModel->setItem(row, 0, new QStandardItem(r));
        m_SongSheetModel->setItem(row, 1, new QStandardItem(""));
        m_SongSheetModel->setItem(row, 2, new QStandardItem(s.getName()));
        m_SongSheetModel->setItem(row, 3, new QStandardItem(s.getArtist()));
        m_SongSheetModel->setItem(row, 4, new QStandardItem(s.getAlbumName()));
        m_SongSheetModel->setItem(row, 5, new QStandardItem(""));
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
private slots :
    void searchIn()
    {

        QString text = search->m_lineSearch->text();
        //qDebug() << text;
        int row = m_SongSheetModel->rowCount();
        for(int i = 0; i < row; i++)
        {
            QModelIndex index = m_SongSheetModel->index(i, 2);
            QString songname = m_SongSheetModel->data(index).toString();
            //qDebug() << songname;
            int j = 0, pos = 0;
            for(j = 0; j < songname.length(); j++)
            {
                if(songname[j] == text[pos]) pos++;
                if(pos == text.length())
                {
                    m_SongSheet->clearSelection();
                    m_SongSheet->selectRow(i);
                    return;
                }

            }

        }
    }
};

#endif // SONGSHEET_H

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
class SongSheet: public QWidget
{
    Q_OBJECT
public:
    SongSheet(QWidget *parent = 0);
    QTableView *m_SongSheet;
    QStandardItemModel *m_SongSheetModel;
    bool addSong(QString name)
    {
        int row=m_SongSheetModel->rowCount();
        m_SongSheetModel->setItem(row, 0, new QStandardItem(name));
        m_SongSheetModel->setItem(row, 1, new QStandardItem("   X"));
        return true;
    }
};

#endif // SONGSHEET_H

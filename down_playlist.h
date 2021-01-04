#ifndef DOWN_PLAYLIST_H
#define DOWN_PLAYLIST_H

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


class Down_PlayList : public QWidget
{
    Q_OBJECT
public:
    explicit Down_PlayList(QWidget *parent = 0);
    QTableView *m_PlayList;
    QStandardItemModel *m_PlayListModel;
    bool addSong(QString name)
    {
        int row=m_PlayListModel->rowCount();
        m_PlayListModel->setItem(row, 0, new QStandardItem(name));
        return true;
    }
};

#endif // DOWN_PLAYLIST_H

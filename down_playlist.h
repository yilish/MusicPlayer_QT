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
};

#endif // DOWN_PLAYLIST_H

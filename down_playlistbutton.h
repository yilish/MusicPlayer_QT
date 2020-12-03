#ifndef DOWN_PLAYLISTBUTTON_H
#define DOWN_PLAYLISTBUTTON_H

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


class Down_PlayListButton : public QWidget
{
    Q_OBJECT
public:
    explicit Down_PlayListButton(QWidget *parent = 0);
    QPushButton *m_btnPlayList;

};

#endif // DOWN_PLAYLISTBUTTON_H

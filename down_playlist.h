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
        m_PlayListModel->item(row, 0)->setBackground(QColor(43,43,43));
        m_PlayListModel->item(row, 0)->setForeground(QColor(213,207,177));
        auto ft = m_PlayListModel->item(row, 0)->font();
        ft.setFamily("Microsoft yahei");
        m_PlayListModel->item(row, 0)->setFont(ft);
        return true;
    }
    QString name = "Local";
};

#endif // DOWN_PLAYLIST_H

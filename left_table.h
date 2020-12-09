#ifndef LEFT_TABLE_H
#define LEFT_TABLE_H

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

class Left_Table : public QWidget
{
    Q_OBJECT
public:
    explicit Left_Table(QWidget *parent = 0);
    QTableView *m_LeftTable;
    QStandardItemModel *m_LeftTableModel;
};

#endif // LEFT_TABLE_H
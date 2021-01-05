#ifndef MIDDLE_SEARCHRESULT_H
#define MIDDLE_SEARCHRESULT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QListView>
#include <QStandardItemModel>
#include <QPainter>
#include <qssparser.h>
#include <searchboxproxystyle.h>

class Middle_searchResult: public QListView
{
    Q_OBJECT
public:
    Middle_searchResult(QWidget* parent = nullptr);
    QStandardItemModel* m_itemModel;
    QStringList* m_strList;
    //void paintEvent(QPaintEvent* event);
    void setList(QStringList* strList);
};

#endif // MIDDLE_SEARCHRESULT_H

#ifndef MIDDLE_SEARCHRESULT_H
#define MIDDLE_SEARCHRESULT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QListView>
#include <QStandardItemModel>

class Middle_searchResult: public QListView
{
    Q_OBJECT
public:
    Middle_searchResult(QWidget* parent = nullptr);
    QStandardItemModel* m_itemModel;
    QStringList* m_strList;
    void setList(QStringList* strList);
};

#endif // MIDDLE_SEARCHRESULT_H

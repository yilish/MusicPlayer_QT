/*
* @Author: YiliShen
* @Date:   2020-12-8
* @Last Modified by:   YiliShen
* @Last Modified time: 2020-12-8
*/
#ifndef TOP_SEARCHWIDGET_H
#define TOP_SEARCHWIDGET_H
#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <qssparser.h>
#include <QAction>
#include <QPainter>

class Top_SearchWidget: public QWidget
{
public:
    explicit Top_SearchWidget(QWidget* parent = nullptr);
    QPushButton* m_btnSearch;
    QAction* m_actionSearch;
    QLineEdit* m_lineSearch;
private:
    void paintEvent(QPaintEvent *event);
signals:

};

#endif // TOP_SEARCHWIDGET_H

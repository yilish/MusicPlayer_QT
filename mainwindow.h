#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "down_playwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
private:
    Ui::MainWindow *ui;
    QWidget* m_downWidget;
    down_playWidget* m_downPlayWidget;
//    void setPrevIcon();         //设置下一首的图标样式
//    void setNextIcon();
//    void setPauseIcon();
//    void setMuteIcon();
    void setDownWidget(QWidget* widget);
    QString root;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void setPrevIcon();         //设置下一首的图标样式
    void setNextIcon();
    void setPauseIcon();
    void setMuteIcon();
    QString root;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"

#include <QApplication>
#include <QStyle>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MusicPlayer");
    w.show();
    return a.exec();
}

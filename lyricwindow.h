#ifndef LYRICWINDOW_H
#define LYRICWINDOW_H

#include <QLabel>
#include <QFont>
#include <QPalette>
#include <QMap>
#include <QList>
#include "lyricline.h"

class LyricWindow: public QWidget
{
public:
    LyricWindow(QWidget* parent);
    void normal(int x);
    void focus(int x);
    void update(qint64 position);
    void getLyric(QList<LyricLine*> l);
private:
    QFont normal_font, focus_font;
    QPalette normal_pal, focus_pal;
    qint64 cur_time, next_time;
    QLabel* lines[9];
    QList<LyricLine*> line;
    int focus_line = 0, top_line = 0, buttom_line = 8, cur_line = 0;
};

#endif // LYRICWINDOW_H

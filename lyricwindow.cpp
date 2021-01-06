#include "lyricwindow.h"
#include <QDebug>
LyricWindow::LyricWindow(QWidget* parent): QWidget(parent)
{
    normal_font.setPointSize(12);
    focus_font.setPointSize(16);
    focus_font.setBold(100);
    normal_pal.setColor(QPalette::WindowText,Qt::gray);
    focus_pal.setColor(QPalette::WindowText,Qt::white);
    cur_time = 0;
    focus_line = 0;
    top_line = 0;
    buttom_line = 8;
    int x = 0, y = 0;
    for(int i = 0; i < 9; i++)
    {
        lines[i] = new QLabel(this);
        lines[i]->setGeometry(x, y, 800, 100);
        y += 40;
    }
}

void LyricWindow::normal(int x)
{
    lines[x]->setFont(normal_font);
    lines[x]->setPalette(normal_pal);
}
void LyricWindow::focus(int x)
{
    lines[x]->setFont(focus_font);
    lines[x]->setPalette(focus_pal);
}
void LyricWindow::update(qint64 position)
{
    int flag = 0;
    int pos = 0;
    for(pos = 0; pos < line.size() - 1; pos++)
    {
        if(line.at(pos + 1)->time > position)
        {
            flag = 1;
            break;
        }
    }
    if(pos != cur_line && flag == 1)
    {
        cur_line = pos;
        for(int i = top_line; i < buttom_line; i++)
        {
            lines[i - top_line]->clear();
            lines[i - top_line]->setText(line.at(i)->text);
            if(i == pos) focus(i - top_line);
            else normal(i - top_line);
        }
        if(pos - 4 < 0) top_line = 0;
        else top_line = pos - 4;
        if(top_line + 9 > line.size()) buttom_line = line.size();
        else buttom_line = top_line + 9;
    }
    /*
    //qint64 pos = position / 10;
    qDebug() << "cur time: " << cur_time;
    qDebug() << "next_time： " << next_time;
    if(position > next_time)
    {
        //qDebug() << next_time;
        cur_time = next_time;
        for(int i = 0; i < 8; i++)
        {
            lines[i]->clear();
            lines[i]->setText(lines[i + 1]->text());
            if(i == focus_line) focus(i);
            else normal(i);
        }
        if(focus_line < 4) focus_line++;
        if(cur_line + 1 < line.size())
        {
            cur_line++;
            next_time = line.at(cur_line)->time;
        }
        else
        {
            focus_line--;
        }
        if(top_line + 1 < line.size())
        {
            top_line++;
        }
        if(buttom_line + 1 < line.size())
        {
            buttom_line++;
            lines[8]->clear();
            lines[8]->setText(line.at(buttom_line)->text);
        }
        else lines[8]->clear();
    }
    */
}
void LyricWindow::getLyric(QList<LyricLine*> l)
{
    cur_time = 0;
    next_time = l.at(0)->time;
    focus_line = 0;
    top_line = 0;
    if(l.size() > 9) buttom_line = 9;
    else buttom_line = l.size();
    cur_line = 0;
    line = l;
    for(int i = top_line; i < buttom_line; i++)
    {
        lines[i]->clear();
        lines[i]->setText(line.at(i)->text);
        if(i == focus_line) focus(i);
        else normal(i);
    }
}


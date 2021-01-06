#ifndef LYRICLINE_H
#define LYRICLINE_H

#include <QString>

class LyricLine
{
public:
    LyricLine(int time, QString text):time(time), text(text){}

    int time;
    QString text;
};

#endif // LYRICLINE_H

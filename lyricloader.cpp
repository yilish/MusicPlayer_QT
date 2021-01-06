#include "lyricloader.h"


#include <QFile>
#include <QTextStream>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QDebug>

QList<LyricLine> mLines;
bool mHasTimer;

bool lyricTimeLessThan(const LyricLine* line1, const LyricLine* line2)
{
    return line1->time < line2->time;
}
QList<LyricLine> getAllLine()
{
    return mLines;
}
bool LyricLoader::loadFromFile(const QString &fileName)
{
    reset();
    QFile file(fileName);
    if (file.size() && file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);

        stream.setCodec("unicode");

        //stream.setAutoDetectUnicode(true);
        return processContent(stream.readAll());
    }
    return false;
}

int LyricLoader::getLineByPosition(const int &millisec, const int &startPos) const
{
    if (!mHasTimer || mLines.isEmpty())
        return -1;

    int result = qBound(0, startPos, mLines.size() - 1);

    if (mLines.at(result)->time <= millisec) {
        while (++result < mLines.size() && mLines.at(result)->time <= millisec);
        return result - 1;
    }
    else {
        while (--result >= 0 && mLines.at(result)->time > millisec);
        return result;
    }
}

bool LyricLoader::dataAvailable() const
{
    return !mLines.isEmpty() && !mRawData.isEmpty();
}

QStringList LyricLoader::lyric() const
{
    QStringList list;
    foreach (LyricLine* line, mLines)
        list.append(line->text);
    return list;
}

bool LyricLoader::hasTimer() const
{
    return mHasTimer;
}

bool LyricLoader::loading() const
{
    return mReply && mReply->isRunning();
}

void LyricLoader::reset()
{
    if (mReply && mReply->isRunning()) {
        mReply->abort();
        mReply = 0;
        emit loadingChanged();
    }
    else {
        mReply = 0;
    }

    mRawData.clear();

    if (!mLines.isEmpty()) {
        qDeleteAll(mLines);
        mLines.clear();
        mHasTimer = false;
        emit lyricChanged();
    }
}

bool LyricLoader::processContent(const QString &content)
{
    if (!mLines.isEmpty()) {
        qDeleteAll(mLines);
        mLines.clear();
        mHasTimer = false;
        emit lyricChanged();
    }

    const QRegExp rx("\\[(\\d+):(\\d+(\\.\\d+)?)\\]"); //用来查找时间标签的正则表达式

    // 步骤1
    int pos = rx.indexIn(content);
    if (pos == -1) {
        QStringList list = content.split('\n', QString::SkipEmptyParts);

        foreach (QString line, list)

            mLines.append(new LyricLine(0, line));

        mHasTimer = false;
    }
    else {
        int lastPos;
        QList<int> timeLabels;
        do {
            // 步骤2
            timeLabels << (rx.cap(1).toInt() * 60 + rx.cap(2).toDouble()) * 1000;
            lastPos = pos + rx.matchedLength();
            pos = rx.indexIn(content, lastPos);
            if (pos == -1) {
                QString text = content.mid(lastPos).trimmed();
                foreach (const int& time, timeLabels)
                    mLines.append(new LyricLine(time, text));
                break;
            }
            // 步骤3
            QString text = content.mid(lastPos, pos - lastPos);
            //qDebug() << text << "123456";
            if (!text.isEmpty()) {
                foreach (const int& time, timeLabels)
                    mLines.append(new LyricLine(time, text.trimmed()));
                timeLabels.clear();
            }
        }
        while (true);
        // 步骤4
        qStableSort(mLines.begin(), mLines.end(), lyricTimeLessThan);
        mHasTimer = true;
    }

    if (!mLines.isEmpty()) {
        emit lyricChanged();
        return true;
    }

    return false;
}

#ifndef QSSPARSER_H
#define QSSPARSER_H
#pragma once
#include <QWidget>
#include <QFile>


class QSSParser
{
public:
    explicit QSSParser(QFile* m_file);
    QString getStyleSheet();
private:
    QFile* m_file;
    QString m_strStyleSheet;
};

#endif // QSSPARSER_H

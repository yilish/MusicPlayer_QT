#include "qssparser.h"

QSSParser::QSSParser(QFile* m_file)
{

    m_file->open(QFile::ReadOnly);
    if (m_file->isOpen()) {
        m_strStyleSheet = QLatin1String(m_file->readAll());
    }
}

QString QSSParser::getStyleSheet() {
    return m_strStyleSheet;

}

#ifndef MIDDLE_MUSICSHOW_H
#define MIDDLE_MUSICSHOW_H
#include <QWidget>
#include <QLabel>

class Middle_musicShow : public QWidget
{
    Q_OBJECT
public:
    Middle_musicShow(QWidget* parent);
    QLabel* m_lblImage;

};

#endif // MIDDLE_MUSICSHOW_H

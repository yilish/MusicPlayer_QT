#ifndef LYRICWINDOW_H
#define LYRICWINDOW_H

#include <QLabel>
class LyricWindow: public QLabel
{
    Q_OBJECT
    public:
        explicit LyricWindow(QWidget *parent = 0, Qt::WindowFlags f=0);
        virtual ~LyricWindow(){}

    public slots:
        void setText(const QString &);

    protected:
        void showEvent(QShowEvent *);
        void paintEvent(QPaintEvent *);
        void timerEvent(QTimerEvent *);
        void hideEvent(QHideEvent *);

    private slots:
        void metrics();
        void startScroll();

    signals:
        void currentTextChanged();

    private:
        int getHeight();

    private:
        int offset;
        int timerID;
        int textHeight;
};

#endif // LYRICWINDOW_H

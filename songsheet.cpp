#include "songsheet.h"
#include "database.h"
SongSheet::SongSheet(QWidget *parent) : QWidget(parent)
{
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background,QColor(60,60,60));
    setAutoFillBackground(true);
    setPalette(pal);
    this->hide();

    //设置播放列表格式
    m_SongSheetModel = new QStandardItemModel;
    m_SongSheetModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("")));
    m_SongSheetModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("")));
    m_SongSheetModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("音乐标题")));
    m_SongSheetModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("歌手")));
    m_SongSheetModel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("专辑")));
    m_SongSheetModel->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("")));
    m_SongSheetModel->setColumnCount(6);

    //m_PlayListModel->setItem(0, 0, new QStandardItem("1"));
    //m_PlayListModel->setItem(1, 0, new QStandardItem("2"));

    //设置播放列表
    m_SongSheet = new QTableView(this);
    m_SongSheet->setGeometry(0, 161, 1050, 500);
    m_SongSheet->setModel(m_SongSheetModel);
    //m_SongSheet->verticalHeader()->hide();
    m_SongSheet->verticalHeader()->setStyleSheet("QHeaderView::section {border: none;border-right: none;border-bottom: none;"
                                                 "color: rgb(214, 214, 214);background-color: rgb(51, 51, 51)}");
    m_SongSheet->setColumnWidth(0, 0);
    m_SongSheet->setColumnWidth(1, 50);
    m_SongSheet->setColumnWidth(2, 430);
    m_SongSheet->setColumnWidth(3, 240);
    m_SongSheet->setColumnWidth(4, 240);
    m_SongSheet->setColumnWidth(5, 50);
    m_SongSheet->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_SongSheet->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_SongSheet->setAlternatingRowColors(true);
    //m_SongSheet->setStyleSheet("background-color:rgb(43,43,43)");
    m_SongSheet->horizontalHeader()->setStyleSheet("QHeaderView::section {border: none;border-right: none;border-bottom: none;"
                                                                       "color: rgb(214, 214, 214);background-color: rgb(51, 51, 51)}");
    //m_SongSheet->horizontalHeader()->setDisabled(true);
    m_SongSheet->setStyleSheet("background-color:rgb(43,43,43); selection-background-color:rgb(51,51,51); QTableView::item:hover {background: rgb(51, 51, 51);}");
    m_SongSheet->setFocusPolicy(Qt::NoFocus);
    m_SongSheet->setFrameShape(QFrame::NoFrame);
    m_SongSheet->setShowGrid(false);
    m_SongSheet->setSortingEnabled(true);

}

void SongSheet::Show()
{
    QString curDir = ":/images/txy1.png";
    if(m_SongSheetModel->rowCount()>=0)
    {
        QModelIndex index = m_SongSheetModel->index(0, 2);
        QString name = m_SongSheetModel->data(index).toString();
        QString songdir;
        QSqlDatabase db = QSqlDatabase::database("QSQLITE"); //建立数据库连接
        QSqlQuery query(db);
        query.prepare(QString("select imagedir from songlist where songname = '%1'").arg(name));
        if(!query.exec())
        {
            qDebug() << "song album image not found";
        }
        else if(query.first())
        {
            curDir = query.value(0).toString();
        }
    }
    QSize sz(136, 136);
    m_cover = new QLabel(this);
    sname = new QLabel(this);
    sname->setText(name);
    QFont ft;
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    sname->setPalette(pa);
    ft.setPointSize(20);
    sname->setFont(ft);
    sname->setGeometry(200, 5, 400, 150);
    QPixmap curPix(curDir);
    m_cover->setPixmap(curPix);
    m_cover->setPixmap(m_cover->pixmap()->scaled(sz, Qt::KeepAspectRatio));
    m_cover->setGeometry(10, 10, 136, 136);


    this->setGeometry(250,69,1050,661);
    this->show();
}

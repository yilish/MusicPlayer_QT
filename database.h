#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>

class DataBase
{
public:
    bool createConnection();  //创建一个连接
    bool createTable();       //创建数据库表
    bool insert(QString id, QString songname, QString artistname, QString dir, QString imagedir, QString lyrdir);//出入数据
    bool queryAll();          //查询所有信息
    bool updateById(int id);  //更新
    bool deleteById(int id);  //删除
    bool sortById();          //排序
    QString querySong(QString name); //查找歌曲本地路径
    QString queryImage(QString name);//find song image dir
    QString queryLyr(QString name);
};

#endif // DATABASE_H

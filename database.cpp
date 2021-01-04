#include "database.h"


//建立一个数据库连接
bool DataBase::createConnection()
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("songlist.db");
        database.setUserName("admin");
        database.setPassword("123456");
    }
    /*
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection")) //判断是否存在这个连接
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE"); //是SQLite对应的驱动名，不能改 第二个参数被省略了，
    }
    //以后就可以用"sqlite1"与数据库进行连接了
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("songlist");
    */
    if(!database.open())
    {
        qDebug() << "connect failed.";
        return false;
    }

    return true;
}

//创建数据库表
bool DataBase::createTable()
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    QSqlQuery sql_query(db);
    QString create_sql = "create table songlist(id varchar primary key,songname varchar,"
                         "artistname varchar,songartist varchar,dir varchar)";
    //sql_query.prepare();
    if(!sql_query.exec(create_sql))
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
    /*
    QSqlDatabase db = QSqlDatabase::database("QSQLITE"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("create table songlist(id varchar primary key,songname varchar,artistname varchar,song-artist varchar,dir varchar)");
    if(success)
    {
        qDebug() << QObject::tr("database created.");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("database create failed.");
        return false;
    }
    */
}

//向数据库中插入记录
bool DataBase::insert(QString id, QString songname, QString artistname, QString dir)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into songlist values(?, ?, ?, ?, ?)");
    query.bindValue(0, id);
    query.bindValue(1, songname);
    query.bindValue(2, artistname);
    query.bindValue(3, songname + "-" + artistname);
    query.bindValue(4, dir);
    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
        return false;
    }
    return true;
}

//查询所有信息
bool DataBase::queryAll()
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from songlist");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("songlist表字段数：" ) << rec.count();

    while(query.next())
    {
        for(int index = 0; index < 5; index++)
            qDebug() << query.value(index) << " ";
        qDebug() << "\n";
    }
}

//根据ID删除记录
bool DataBase::deleteById(int id)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("delete from songlist where id = %1").arg(id));
    if(!query.exec())
    {
        qDebug() << "delete failed.";
        return false;
    }
    return true;
}

//根据ID更新记录
bool DataBase::updateById(int id)
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update songlist set attribute=?,type=?,"
                             "kind=?, nation=?,"
                             "carnumber=?, elevaltor=?,"
                             "distance=?, oil=?,"
                             "temperature=? where id=%1").arg(id));

     query.bindValue(0,"四轮");
     query.bindValue(1,"轿车");
     query.bindValue(2,"富康");
     query.bindValue(3,rand()%100);
     query.bindValue(4,rand()%10000);
     query.bindValue(5,rand()%300);
     query.bindValue(6,rand()%200000);
     query.bindValue(7,rand()%52);
     query.bindValue(8,rand()%100);

     bool success=query.exec();
     if(!success)
     {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("update database failed."));
     }
    return true;
}

//排序
bool DataBase::sortById()
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE"); //建立数据库连接
    QSqlQuery query(db);
    bool success=query.exec("select * from songlist order by id desc");
    if(success)
    {
        qDebug() << QObject::tr("database sorted.");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("database sort failed.");
        return false;
    }
}

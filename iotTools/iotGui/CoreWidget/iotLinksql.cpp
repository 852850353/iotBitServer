#include "iotLinksql.h"

linkSQL::linkSQL()
{
    hostName = "";
    databaseName = "";
    userName = "";
    password = "";

    type = 0;

    if( sql == nullptr)
        sql = new  QSqlDatabase;
}

linkSQL::~linkSQL()
{
    if(sql != nullptr)
    {
        delete sql;
        sql = nullptr;
    }
}

bool linkSQL::linkiotTimeDB()
{
    type = Type::timeDB;
    sql = nullptr;
    //   sql = new QSqlDatabase(QSqlDatabase::database(""));

    //    bool ok = sql->open();
    //    if (ok)
    //    {
    //        qDebug() << "连接iotTimeDB数据库ok";
    //    }
    //    else
    //    {
    //        qDebug() << "连接iotTimeDB数据库失败";
    //    }
    return true;
}

bool linkSQL::linksqlite(QString name)
{
    type = Type::sqlite;
    sql = nullptr;
    sql = new QSqlDatabase(QSqlDatabase::database("QSQLITE"));
    sql->setDatabaseName(name);
    bool ok = sql->open();
    if (ok)
    {
        qDebug() << "连接sqlite数据库ok";
    }
    else
    {
        qDebug() << "连接sqlite数据库失败";
    }
    return ok;
}

bool linkSQL::linkMYsql(QString hostname,QString databasename,QString username,QString Password)
{
    type = Type::MYsql;
    sql = nullptr;
    sql = new QSqlDatabase(QSqlDatabase::database("QMYSQL"));
    sql->setHostName(hostname);
    sql->setDatabaseName(databasename);
    sql->setUserName(username);
    sql->setPassword(Password);
    bool ok = sql->open();
    if (ok)
    {
        qDebug() << "连接MYsql数据库ok";
    }
    else
    {
        qDebug() << "连接MYsql数据库失败";
    }
    return ok;
}


void linkSQL::queryDB(QString str)
{
    QSqlQuery query(*sql);
    bool ok = query.exec(str);
    if (!ok)
    {
        qDebug() << "失败";
    }

}

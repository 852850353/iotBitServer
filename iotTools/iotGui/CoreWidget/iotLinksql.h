#ifndef LINKSQL_H
#define LINKSQL_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>

enum Type
{
    timeDB=2,
    sqlite,
    MYsql
};


class linkSQL
{
public:
    linkSQL();
    ~linkSQL();

   bool linkiotTimeDB();
   bool linksqlite(QString name);
   bool linkMYsql(QString hostname, QString databasename, QString username, QString Password);

   int type;

   void queryDB(QString str);
private:
   QSqlDatabase *sql = nullptr;

   QString hostName;
   QString databaseName;
   QString userName;
   QString password;

};

#endif // LINKSQL_H

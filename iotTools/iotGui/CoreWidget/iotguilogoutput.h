#ifndef IOTGUILOGOUTPUT_H
#define IOTGUILOGOUTPUT_H

#include <QString>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QMutex>
#include <QCoreApplication>

enum QLogType   //输出信息类型
{
    Log = 0,
    MYsqlLog,
    sqliteLog,
    timeDBLog
};

class iotGuiLogOutPut
{
public:
    //获取指针
    static iotGuiLogOutPut* GetiotGuiLogOutPut();

    void OutPutLog(QString strlog,QLogType logType = QLogType::Log);

    QString fileName;  //log文件Name

private:
    iotGuiLogOutPut();
    ~iotGuiLogOutPut();

      static  QMutex m_pMutex;

       QString startTime; //log 起始时间
       int startTimeDay;  //log 起始时间 day


       //析构类
       class Garbo
       {
       public:
           ~Garbo()
           {
               if(iotGuiLogOutPut::iotOutPutLog != nullptr)
               {
                   delete  iotGuiLogOutPut::iotOutPutLog ;
                   iotGuiLogOutPut::iotOutPutLog = nullptr;
               }
           }
       };

      static Garbo garbo;
      static iotGuiLogOutPut* iotOutPutLog;

};

#endif // IOTGUILOGOUTPUT_H

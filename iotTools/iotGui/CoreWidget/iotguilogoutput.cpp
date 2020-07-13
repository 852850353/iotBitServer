#include "iotguilogoutput.h"


iotGuiLogOutPut::Garbo iotGuiLogOutPut::garbo;
iotGuiLogOutPut* iotGuiLogOutPut::iotOutPutLog = new iotGuiLogOutPut();
QMutex iotGuiLogOutPut::m_pMutex;

iotGuiLogOutPut::iotGuiLogOutPut()
{
    startTime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString startTime1 = QDateTime::currentDateTime().toString("hh:mm:ss");
    startTimeDay = QDateTime::currentDateTime().toString("dd").toInt();

    fileName = startTime+".txt";
}

iotGuiLogOutPut::~iotGuiLogOutPut()
{

}

iotGuiLogOutPut *iotGuiLogOutPut::GetiotGuiLogOutPut()
{
    return iotOutPutLog;
}
void iotGuiLogOutPut::OutPutLog(QString strlog, QLogType logType)
{
    m_pMutex.lock();

    if( 1 == QDateTime::currentDateTime().toString("dd").toInt() - startTimeDay)   //log文本以one day为界限
    {
        startTime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        startTimeDay = QDateTime::currentDateTime().toString("dd").toInt();
        fileName = startTime + ".txt";
    }

    QFile file;

    file.setFileName(QCoreApplication::applicationDirPath() +"/"+ fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append))
    {
        qDebug()<<"log file open failed";
        return;
    }

    QTextStream in(&file);
    QString data = "";

    if(logType == QLogType::MYsqlLog)
    {
        //qDebug()<< "MYsqlLog" <<":"<< log;
        in<<QDateTime::currentDateTime().toString("hh:mm:ss")<<"-MYsqlLog :"<< strlog <<"\n";
        data = QDateTime::currentDateTime().toString("hh:mm:ss")+"-MYsqlLog :"+ strlog +"\n";
    }
    else if(logType == QLogType::sqliteLog)
    {
        //qDebug()<< "sqliteLog" <<":"<< log;
        in<<QDateTime::currentDateTime().toString("hh:mm:ss")<<"-sqliteLog :"<< strlog <<"\n";
        data = QDateTime::currentDateTime().toString("hh:mm:ss")+"-sqliteLog :"+ strlog +"\n";
    }
    else if(logType == QLogType::timeDBLog)
    {
        //qDebug()<< "timeDBLog" <<":"<< log;
        in<<QDateTime::currentDateTime().toString("hh:mm:ss")<<"-timeDBLog :"<< strlog <<"\n";
        data = QDateTime::currentDateTime().toString("hh:mm:ss")+"-timeDBLog :"+ strlog +"\n";
    }
    else if(logType == QLogType::Log)
    {
        //qDebug()<< "Log" <<":"<< log;
        in<<QDateTime::currentDateTime().toString("hh:mm:ss")<<"-Log :"<< strlog <<"\n";
        data = QDateTime::currentDateTime().toString("hh:mm:ss")+"-Log :"+ strlog +"\n";
    }

    file.close();

    m_pMutex.unlock();
}


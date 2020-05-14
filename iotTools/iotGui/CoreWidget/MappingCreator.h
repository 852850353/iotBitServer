#ifndef MAPPINGCREATOR
#define MAPPINGCREATOR

#include <QString>

#include <QWidget>

#include <QtPlugin>

#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QFileInfo>
#include <QByteArray>
#include <QMenuBar>
#include <QRect>

class MappingCreator:public QWidget
{
    Q_OBJECT
public:
    static MappingCreator* getInstance()
    {
        if(!This) This = new MappingCreator();
        return This;
    }

    static bool loadPulgin(QString path,QString name)
    {
        QFileInfo finfo(path);
        if(finfo.isFile())
        {

        }
        else return false;
    }

    static void LogWrite2File(QString fmtTime,QString mess,QString logFilePath)
    {
        QFile logFile(logFilePath);
        if(!logFile.exists())
        {
            if(logFile.open(QFile::OpenModeFlag::Append))
            {
                logFile.write(QString("[" + fmtTime + "]:" + mess).toLocal8Bit());
                logFile.close();
            }
        }
    }

    static QString getDate()
    {
        return QDateTime::currentDateTime().date().toString();
    }

    static QString getTime()
    {
        return QDateTime::currentDateTime().time().toString();
    }


    MappingCreator* operator<<(QString log)
    {
        LogWrite2File(getDate()+" "+getTime(),log,ms_logFilePath);
        return This;
    }

private:
    struct White//插件白名单
    {
       char pluginType[64];
       char classType[64];
       char fileName[256];
    };

    static QString ms_logFilePath;

    static MappingCreator* This;

    QMenuBar m_menuBar;

    MappingCreator(QWidget *parent = nullptr);

    static QList<White> ms_listWhites;
};
#endif

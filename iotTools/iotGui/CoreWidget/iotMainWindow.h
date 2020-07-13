#ifndef IOTMAINWINDOW_H
#define IOTMAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QMenu>
#include <QAction>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <algorithm>
#include <QProcess>
#include <QCoreApplication>

#include "iotServerEdit.h"
#include "iotServerNodeTree.h"

#include "iotLinksql.h"
#include "iotguilogoutput.h"


enum  CaseType
{
     bandsType = 0,        //info
     infoType,       //info
     treeType,        //tree
     MYsqlType,        //MYsqlDb 连接
     sqliteType,        // sqlite Db 连接
     iottimeType,       // iottime Db 连接
    connectNode,//connectNode,
    link_Node,//link_Node,
    create_Bands_Hander//create_Bands_Hander
};

namespace Ui {
class iotMainWindow;
}

class iotMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit iotMainWindow(QWidget *parent = nullptr);
    ~iotMainWindow();

private:
    Ui::iotMainWindow *ui;

    QSplitter m_Splitter;
    QSplitter m_Splitter1;

    iotServerEdit m_ServerEdit;
    iotServerNodeTree m_ServerNT;

    QVBoxLayout verLayout;

    QMenu   Menu;
    QAction AddAction;
    QAction DeleteAction;

    QAction tableViewJumpAction;
    QAction tableViewSectionAction;
    QAction tableViewSpanAction;

    int type;

    QPoint nodePoint;
    QWidget addWidget;
    QGridLayout layout;
    QLabel lable1;
    QLineEdit lineEdit1;
    QLabel lable2;
    QLineEdit lineEdit2;
    QLabel lable3;
    QLineEdit lineEdit3;
    QLabel lable4;
    QLineEdit lineEdit4;
    QLabel lable5;
    QLineEdit lineEdit5;
    QHBoxLayout  hlayout;
    QPushButton yesButton;
    QPushButton noButton;

    linkSQL db;

    QProcess logpro;

    void setHideAndShow(CaseType type);//显示隐藏

    QVector<int> getSelectedRow(); //获取右边tableview选中得那些行
public slots:
    void clickNodeORItemSlot(int type);
    void clickBlanSlot(int type);
    void AddActionClickSlot();
    void DeleteActionClickSlot();
    void yesButtonClickSlot();  //确定按钮触发   staut在此改变值
};

#endif // IOTMAINWINDOW_H

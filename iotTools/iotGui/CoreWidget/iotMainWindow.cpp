#include "iotMainWindow.h"
#include "ui_iotMainWindow.h"


iotMainWindow::iotMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iotMainWindow)
{

    ui->setupUi(this);

    m_Splitter.setOrientation(Qt::Horizontal);

    m_Splitter.addWidget(&this->m_ServerNT);
    m_Splitter.addWidget(&this->m_ServerEdit);

    ui->centralwidget->setLayout(&verLayout);
    verLayout.addWidget(&m_Splitter);

    //m_Splitter.setStyleSheet("border:1px solid #00AACC");

    AddAction.setText("添加");
    DeleteAction.setText("删除");

    tableViewJumpAction.setText("跳转");;
    tableViewSectionAction.setText("搜索");
    tableViewSpanAction.setText("合并");

    addWidget.setWindowTitle("添加");

    addWidget.setLayout(&layout);

    yesButton.setText("确定");
    noButton.setText("取消");

    hlayout.addWidget(&yesButton);
    hlayout.addWidget(&noButton);


    layout.addWidget(&lable1,0,0,1,1);
    layout.addWidget(&lineEdit1,0,1,1,3);
    layout.addWidget(&lable2,1,0,1,1);
    layout.addWidget(&lineEdit2,1,1,1,3);
    layout.addWidget(&lable3,2,0,1,1);
    layout.addWidget(&lineEdit3,2,1,1,3);
    layout.addWidget(&lable4,3,0,1,1);
    layout.addWidget(&lineEdit4,3,1,1,3);
    layout.addWidget(&lable5,4,0,1,1);
    layout.addWidget(&lineEdit5,4,1,1,3);
    layout.addLayout(&hlayout,5,0,1,4);


    //左边树 鼠标右键
    connect(&m_ServerNT,SIGNAL(clickNodeSignal(int)),this,SLOT(clickNodeORItemSlot(int)));
    connect(&m_ServerNT,SIGNAL(clickBlanSignal(int)),this,SLOT(clickBlanSlot(int)));

    //添加按钮 和 删除按钮
    connect(&AddAction,SIGNAL(triggered()),this,SLOT(AddActionClickSlot()));
    connect(&DeleteAction,SIGNAL(triggered()),this,SLOT(DeleteActionClickSlot()));

    //确定按钮 和 取消按钮
    connect(&yesButton,SIGNAL(clicked()),this,SLOT(yesButtonClickSlot()));
    connect(&noButton,&QPushButton::clicked,[=](){addWidget.close();});


    //左边树treeItem左键单击
    connect(m_ServerNT.getTree(),&QTreeWidget::itemClicked,[=](QTreeWidgetItem *item, int colum){
        iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("treeItem左键单击");
    });

    //右边tableview 鼠标右键
    connect(&m_ServerEdit,SIGNAL(clickItemSignal(int)),this,SLOT(clickNodeORItemSlot(int)));
    connect(&m_ServerEdit,SIGNAL(clickItemBlanSignal(int)),this,SLOT(clickBlanSlot(int)));

    //合并
    connect(&tableViewSpanAction,&QAction::triggered,[=](){

        iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("合并");
        Menu.close();
        QVector<int> inde = getSelectedRow();
        //选择选定inde中合并
    });
    //跳转
    connect(&tableViewJumpAction,&QAction::triggered,[=](){iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("跳转");});
    //搜索
    connect(&tableViewSectionAction,&QAction::triggered,[=](){iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("搜索");});

    //链接MySql
    connect(ui->actionMySql,&QAction::triggered,[=](){
        type = CaseType::MYsqlType;
        addWidget.setFixedSize(250,250);

        lable1.setText("hostname");
        lable2.setText("databasename");
        lable3.setText("username");
        lable4.setText("Password");

        setHideAndShow(CaseType::MYsqlType);
        addWidget.show();
        addWidget.move(QCursor::pos());
    });

    //链接Sqllite
    connect(ui->actionSqllite,&QAction::triggered,[=](){
        type = CaseType::sqliteType;

        Menu.close();
        addWidget.setFixedSize(250,100);
        lable1.setText("databasename");

        setHideAndShow(CaseType::sqliteType);
        addWidget.show();
        addWidget.move(QCursor::pos());
    });

    //链接iotDataBase
    connect(ui->actioniotDataBase,&QAction::triggered,[=](){
        type = CaseType::iottimeType;
        // addWidget.show();
        // addWidget.move(QCursor::pos());
    });

    //ShowLog
    connect(ui->actionShowLog,&QAction::triggered,[=](){
        QString path = "notepad.exe " + QCoreApplication::applicationDirPath() +"/"+ iotGuiLogOutPut::GetiotGuiLogOutPut()->fileName;
        logpro.start(path);
    });

    //创建节点
    connect(ui->actionCreateNode,&QAction::triggered,[=](){

        type = CaseType::treeType;

        addWidget.setFixedSize(250,100);
        lable1.setText("节点名称");
        setHideAndShow(CaseType::treeType);
        addWidget.show();
        addWidget.move(QCursor::pos());
    });

    //actionConnectNode
    connect(ui->actionConnectNode,&QAction::triggered,[=](){
        type = CaseType::connectNode;
        iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("actionConnectNode");
    });
    //actionLink_Node
    connect(ui->actionLink_Node,&QAction::triggered,[=](){
        type = CaseType::link_Node;
        iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("actionLink_Node");
    });
    //actionCreate_Bands_Hander
    connect(ui->actionCreate_Bands_Hander,&QAction::triggered,[=](){
        type = CaseType::create_Bands_Hander;
        iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("actionCreate_Bands_Hander");
    });

    iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("初始化完成");
}

iotMainWindow::~iotMainWindow()
{
    delete ui;
}

void iotMainWindow::clickNodeORItemSlot(int typ)
{
    this->type = typ;
    if(type == CaseType::bandsType)       //
    {
        qDebug()<<"bandsType clickNodeORItemSlot";
    }
    else if(type == CaseType::infoType)       //
    {
        Menu.clear();
        Menu.addAction(&AddAction);
        Menu.addAction(&DeleteAction);
        if(getSelectedRow().size() == 1)
        {
            Menu.addAction(&tableViewJumpAction);
            Menu.addAction(&tableViewSectionAction);
        }
        if(getSelectedRow().size()>1)
            Menu.addAction(&tableViewSpanAction);
        Menu.exec(QCursor::pos());

    }
    else if(type == CaseType::treeType)  //tree
    {
        Menu.clear();
        Menu.addAction(&DeleteAction);
        Menu.addAction(&AddAction);
        Menu.exec(QCursor::pos());
    }
}

void iotMainWindow::clickBlanSlot( int typ)
{
    type = typ;
    if(type == CaseType::bandsType)       //
    {
        qDebug()<<"bandsType clickBlanSlot";
    }
    else if(type == CaseType::infoType)       //bands
    {
        Menu.clear();
        Menu.addAction(&AddAction);
        Menu.exec(QCursor::pos());
    }
    else if(type == CaseType::treeType)  //tree
    {
        Menu.clear();
        Menu.addAction(&AddAction);
        Menu.exec(QCursor::pos());
    }
}

void iotMainWindow::setHideAndShow(CaseType type)
{
    switch (type) {
    case CaseType::infoType:
        for (int k = 1; k < layout.rowCount()-1;++k)
        {
            for(int j=0;j<layout.columnCount();j++)
            {
                layout.itemAtPosition(k, j)->widget()->setHidden(false);
            }
        }
        break;
    case CaseType::treeType:
        for (int k = 1; k < layout.rowCount()-1;++k)
        {
            for(int j=0;j<layout.columnCount();j++)
            {
                layout.itemAtPosition(k, j)->widget()->setHidden(true);
            }
        }
        break;
    case CaseType::MYsqlType:
        for (int k = 1; k < layout.rowCount()-1;++k)
        {
            for(int j=0;j<layout.columnCount();j++)
            {
                if( k == layout.rowCount() - 2)
                    layout.itemAtPosition(k, j)->widget()->setHidden(true);
                else
                    layout.itemAtPosition(k, j)->widget()->setHidden(false);
            }
        }
        break;
    case CaseType::sqliteType:
        for (int k = 1; k < layout.rowCount()-1;++k)
        {
            for(int j=0;j<layout.columnCount();j++)
            {
                layout.itemAtPosition(k, j)->widget()->setHidden(true);
            }
        }
        break;
    case CaseType::iottimeType:
        break;
    default:
        break;
    }
}

QVector<int> iotMainWindow::getSelectedRow()
{
    QItemSelectionModel *model_selection = m_ServerEdit.getTableView()->selectionModel();
    QModelIndexList IndexList= model_selection->selectedIndexes();
    QVector<int> inde;
    for (auto modelindex:IndexList)
    {

        if(inde.size() >0)
        {
            if(!std::count(inde.begin(), inde.end(),((QModelIndex)modelindex).row()))
                inde.push_back(((QModelIndex)modelindex).row());
        }
        else
            inde.push_back(((QModelIndex)modelindex).row());
    }
    model_selection = nullptr;
    return inde;
}

void iotMainWindow::AddActionClickSlot()
{
    if(type == CaseType::infoType)       //bands
    {
        Menu.close();

        addWidget.setFixedSize(250,250);

        lable1.setText("第一列");
        lable2.setText("第二列");
        lable3.setText("第三列");
        lable4.setText("第四列");
        lable5.setText("第五列");

        setHideAndShow(CaseType::infoType);
        addWidget.show();
        addWidget.move(QCursor::pos());
    }
    else if(type == CaseType::treeType)  //tree
    {
        Menu.close();
        addWidget.setFixedSize(250,100);
        lable1.setText("节点名称");

        setHideAndShow(CaseType::treeType);
        addWidget.show();
        addWidget.move(QCursor::pos());
    }
}

void iotMainWindow::DeleteActionClickSlot()
{
    if(type == CaseType::infoType)       //bands
    {
        Menu.close();
        QVector<int> inde = getSelectedRow();
        for(int i = inde.size()-1;i>=0;i--)
            m_ServerEdit.deleteItem(i);
    }
    else if(type == CaseType::treeType)  //tree
    {
        Menu.close();
        m_ServerNT.deleteItem();
    }
}

void iotMainWindow::yesButtonClickSlot()
{
    switch (type)
    {
    case CaseType::infoType:
        if(lineEdit1.text().isEmpty() || lineEdit2.text().isEmpty() || lineEdit3.text().isEmpty() || lineEdit4.text().isEmpty() || lineEdit5.text().isEmpty())
        {
            addWidget.close();
            QMessageBox::about(this, "警告框", "有空行");
            addWidget.show();
        }
        else
        {
            m_ServerEdit.addItem(QStringList()<<lineEdit1.text()<<lineEdit2.text()<<lineEdit3.text()<<lineEdit4.text()<<lineEdit5.text());
            lineEdit1.clear(); lineEdit2.clear(); lineEdit3.clear(); lineEdit4.clear(); lineEdit5.clear();
            addWidget.close();
        }
        break;
    case CaseType::treeType:
        if(lineEdit1.text().isEmpty())
        {
            addWidget.close();
            QMessageBox::about(this, "警告框", "节点名字为空");
            addWidget.show();
        }
        else
        {
            m_ServerNT.addItem(lineEdit1.text());
            lineEdit1.clear();
            addWidget.close();
        }
        break;
    case CaseType::MYsqlType:
        if(lineEdit1.text().isEmpty() || lineEdit2.text().isEmpty() || lineEdit3.text().isEmpty() || lineEdit4.text().isEmpty() )
        {
            addWidget.close();
            QMessageBox::about(this, "警告框", "节点名字为空");
            addWidget.show();
        }
        else
        {
            bool ok  =  db.linkMYsql(lineEdit1.text(),lineEdit2.text(),lineEdit3.text(),lineEdit4.text());
            lineEdit1.clear(); lineEdit2.clear(); lineEdit3.clear(); lineEdit4.clear();
            addWidget.close();

            //改变start状态
        }
        break;
    case CaseType::sqliteType:
        if(lineEdit1.text().isEmpty())
        {
            addWidget.close();
            QMessageBox::about(this, "警告框", "节点名字为空");
            addWidget.show();
        }
        else
        {
            bool ok  =  db.linksqlite(lineEdit1.text());
            lineEdit1.clear();
            addWidget.close();
            //改变start状态
        }
        break;
    case CaseType::iottimeType:
        db.linkiotTimeDB();
        iotGuiLogOutPut::GetiotGuiLogOutPut()->OutPutLog("iotdb 连接");
        //改变start状态
        break;
    default:
        break;
    }
}


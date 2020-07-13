#include "iotServerEdit.h"
#include "ui_iotServerEdit.h"

iotServerEdit::iotServerEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iotServerEdit)
{
    ui->setupUi(this);

    ui->tableView_2->setContextMenuPolicy(Qt::CustomContextMenu);//控件右键

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);//控件右键

    ui->tableView_2->setModel(&model);

    model.setHorizontalHeaderLabels(QStringList()<<"第一"<<"第二"<<"第三"<<"第四"<<"第五");
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    connect(ui->tableView_2,SIGNAL(customContextMenuRequested(const QPoint)),this,SLOT(menuSlot(const QPoint)));

    connect(ui->tableView,SIGNAL(customContextMenuRequested(const QPoint)),this,SLOT(menu1Slot(const QPoint)));

}

iotServerEdit::~iotServerEdit()
{
    delete ui;
}

void iotServerEdit::addItem(QStringList data)
{
    int row = ui->tableView_2->model()->rowCount();


    for(int i=0;i<ui->tableView_2->model()->columnCount();i++)
    {
        model.setItem(row,i,new QStandardItem(data[i]));
    }
}

void iotServerEdit::deleteItem(int row)
{
    model.removeRow(row);
}

QTableView *iotServerEdit::getTableView()
{
    return ui->tableView_2;
}

void iotServerEdit::menuSlot(const QPoint poin)
{
    QPoint point(poin);
    QModelIndex index = ui->tableView_2->indexAt(point);
     if(index.isValid())
     {
           emit clickItemSignal(1);
           qDebug()<<"tableView_2 clickNodeSignal";
     }
     else
     {
           emit clickItemBlanSignal(1);
           qDebug()<<"tableView_2 clickBlanSignal";
     }
}

void iotServerEdit::menu1Slot(const QPoint poin)
{
    QPoint point(poin);
    QModelIndex index = ui->tableView->indexAt(point);
     if(index.isValid())
     {
           emit clickItemSignal(0);
           qDebug()<<"tableView clickNodeSignal";
     }
     else
     {
           emit clickItemBlanSignal(0);
           qDebug()<<"tableView clickBlanSignal";
     }
}

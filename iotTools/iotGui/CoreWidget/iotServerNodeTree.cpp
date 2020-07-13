#include "iotServerNodeTree.h"
#include "ui_iotServerNodeTree.h"

iotServerNodeTree::iotServerNodeTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iotServerNodeTree)
{
    ui->setupUi(this);

    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);//控件右键

    connect(ui->treeWidget,SIGNAL(customContextMenuRequested(const QPoint)),this,SLOT(menuSlot(const QPoint)));
}

iotServerNodeTree::~iotServerNodeTree()
{
    delete ui;
}

void iotServerNodeTree::addItem(QString itemname)
{
    new QTreeWidgetItem(ui->treeWidget,QStringList(itemname));
}

void iotServerNodeTree::deleteItem()
{
    ui->treeWidget->model()->removeRow(ui->treeWidget->currentIndex().row());
}

QTreeWidget *iotServerNodeTree::getTree()
{
    return ui->treeWidget;
}

void iotServerNodeTree::menuSlot(const QPoint poin)
{
    QPoint point(poin);
    QModelIndex index = ui->treeWidget->indexAt(point);
     if(index.isValid())
     {
            emit clickNodeSignal(2);
     }
     else
     {
             emit clickBlanSignal(2);
     }
}


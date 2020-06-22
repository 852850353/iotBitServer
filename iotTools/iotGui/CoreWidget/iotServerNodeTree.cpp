#include "iotServerNodeTree.h"
#include "ui_iotServerNodeTree.h"

iotServerNodeTree::iotServerNodeTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iotServerNodeTree)
{
    ui->setupUi(this);
}

iotServerNodeTree::~iotServerNodeTree()
{
    delete ui;
}

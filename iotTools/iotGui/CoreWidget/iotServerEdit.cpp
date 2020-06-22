#include "iotServerEdit.h"
#include "ui_iotServerEdit.h"

iotServerEdit::iotServerEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iotServerEdit)
{
    ui->setupUi(this);
}

iotServerEdit::~iotServerEdit()
{
    delete ui;
}

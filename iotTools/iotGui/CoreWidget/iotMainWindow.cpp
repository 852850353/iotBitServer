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

    this->setStyleSheet("border:1px solid #00AACC");
    m_Splitter.setChildrenCollapsible(false);

}

iotMainWindow::~iotMainWindow()
{
    delete ui;
}

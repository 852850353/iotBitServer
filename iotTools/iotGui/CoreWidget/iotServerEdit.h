#ifndef IOTSERVEREDIT_H
#define IOTSERVEREDIT_H

#include <QWidget>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
namespace Ui {
class iotServerEdit;
}

class iotServerEdit : public QWidget
{
    Q_OBJECT

public:
    explicit iotServerEdit(QWidget *parent = nullptr);
    ~iotServerEdit();

    void addItem(QStringList itemname);
    void deleteItem(int row);

     QTableView *getTableView();

     void setTexteditShow(bool ok);
public slots:

     void menuSlot(const QPoint poin);
     void menu1Slot(const QPoint poin);
private:
    Ui::iotServerEdit *ui;

    QStandardItemModel model;

signals:
    void clickItemSignal(int type);
    void clickItemBlanSignal(int type);
    void clickLeftButtonSignal(QPoint point);
};

#endif // IOTSERVEREDIT_H

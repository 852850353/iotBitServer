#ifndef IOTSERVERNODETREE_H
#define IOTSERVERNODETREE_H

#include <QWidget>
#include <QMouseEvent>
#include <QModelIndex>
#include <QTreeWidgetItem>
#include <QMouseEvent>
#include <QDebug>


namespace Ui {
class iotServerNodeTree;
}

class iotServerNodeTree : public QWidget
{
    Q_OBJECT

public:
    explicit iotServerNodeTree(QWidget *parent = nullptr);
    ~iotServerNodeTree();

    void addItem(QString itemname);

    void deleteItem();

    QTreeWidget *getTree();

private:
    Ui::iotServerNodeTree *ui;

public slots:
    void menuSlot(const QPoint poin);

signals:
    void clickNodeSignal(int type);
    void clickBlanSignal(int type);
    void clickLeftButtonSignal(QPoint point);
};

#endif // IOTSERVERNODETREE_H

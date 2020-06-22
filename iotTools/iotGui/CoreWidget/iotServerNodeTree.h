#ifndef IOTSERVERNODETREE_H
#define IOTSERVERNODETREE_H

#include <QWidget>

namespace Ui {
class iotServerNodeTree;
}

class iotServerNodeTree : public QWidget
{
    Q_OBJECT

public:
    explicit iotServerNodeTree(QWidget *parent = nullptr);
    ~iotServerNodeTree();

private:
    Ui::iotServerNodeTree *ui;
};

#endif // IOTSERVERNODETREE_H

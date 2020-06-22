#ifndef IOTSERVEREDIT_H
#define IOTSERVEREDIT_H

#include <QWidget>

namespace Ui {
class iotServerEdit;
}

class iotServerEdit : public QWidget
{
    Q_OBJECT

public:
    explicit iotServerEdit(QWidget *parent = nullptr);
    ~iotServerEdit();

private:
    Ui::iotServerEdit *ui;
};

#endif // IOTSERVEREDIT_H

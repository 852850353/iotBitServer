#ifndef IOTMAINWINDOW_H
#define IOTMAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QTextEdit>
#include "iotServerEdit.h"
#include "iotServerNodeTree.h"
#include <QVBoxLayout>
#include <QDockWidget>

namespace Ui {
class iotMainWindow;
}

class iotMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit iotMainWindow(QWidget *parent = nullptr);
    ~iotMainWindow();

private:
    Ui::iotMainWindow *ui;

    QSplitter m_Splitter;
    iotServerEdit m_ServerEdit;
    iotServerNodeTree m_ServerNT;
    QVBoxLayout verLayout;
};

#endif // IOTMAINWINDOW_H

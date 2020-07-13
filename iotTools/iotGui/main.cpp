#include "iotMainWindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    iotMainWindow w;
    w.show();

    return a.exec();
}

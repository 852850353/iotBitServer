#include <QApplication>
#include "MappingCreator.h"

int main(int argc, char* argv[])
{
    QApplication a(argc,argv);

    MappingCreator::getInstance()->show();

    return a.exec();
}

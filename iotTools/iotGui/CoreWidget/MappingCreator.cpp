#include "MappingCreator.h"
#include <QApplication>

MappingCreator* MappingCreator::This = nullptr;

QString MappingCreator::ms_logFilePath = QApplication::applicationDirPath() + "\\logs\\" + MappingCreator::getDate();

MappingCreator::MappingCreator(QWidget *parent): QWidget(parent)
{
    m_menuBar.setParent(this);
}

#ifndef TABLEVIEWDELEGATE_H
#define TABLEVIEWDELEGATE_H

#include <QStyledItemDelegate>
#include <QCheckBox>
#include <QApplication>
#include <QMouseEvent>

class TableViewDelegate: public QStyledItemDelegate
{
public:
    TableViewDelegate();
protected:
        void paint(QPainter* painter,const QStyleOptionViewItem& option,const QModelIndex& index) const;
        bool editorEvent(QEvent *event,QAbstractItemModel *model,const QStyleOptionViewItem &option,const QModelIndex &index);
        static QRect CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions);  //返回控件大小格式
};



#endif // TABLEVIEWDELEGATE_H

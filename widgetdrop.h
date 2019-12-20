#ifndef WIDGETDROP_H
#define WIDGETDROP_H

#include <QWidget>

namespace Ui {
class CWidgetDrop;
}

class CWidgetDrop : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetDrop(QWidget *parent = nullptr);
    ~CWidgetDrop();

//    void dragEnterEvent(QDragEnterEvent *e);
//    void dropEvent(QDropEvent *e);
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::CWidgetDrop *ui;
};

#endif // WIDGETDROP_H

#ifndef WIDGETEVENT_H
#define WIDGETEVENT_H

#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>

namespace Ui {
class CWidgetEvent;
}

class CWidgetEvent : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetEvent(QWidget *parent = nullptr);
    ~CWidgetEvent();

protected:
    bool event(QEvent *event); //事件处理方式1：重写虚函数QObject::event()
    void mousePressEvent(QMouseEvent* e); //事件处理方式2：重写QWidget类中的此虚函数
    void keyPressEvent(QKeyEvent *event);
    bool notify(QObject *obj, QEvent *event);


private:
    Ui::CWidgetEvent *ui;
};

#endif // WIDGETEVENT_H

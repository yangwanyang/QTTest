#ifndef WIDGETMENU_H
#define WIDGETMENU_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class CWidgetMenu;
}

class CWidgetMenu : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetMenu(QWidget *parent = nullptr);
    ~CWidgetMenu();

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private slots:
    void SlotAction4();

private:
    Ui::CWidgetMenu *ui;
    QMenu* m_pMyMenu;
};

#endif // WIDGETMENU_H

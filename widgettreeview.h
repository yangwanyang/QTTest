#ifndef WIDGETTREEVIEW_H
#define WIDGETTREEVIEW_H

#include <QWidget>
#include <QFileSystemModel>

namespace Ui {
class CWidgetTreeView;
}

class CWidgetTreeView : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetTreeView(QWidget *parent = nullptr);
    ~CWidgetTreeView();

private:
    Ui::CWidgetTreeView *ui;
    QFileSystemModel* m_pFileModel;
};

#endif // WIDGETTREEVIEW_H

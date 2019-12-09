#ifndef WIDGETTREEVIEW_H
#define WIDGETTREEVIEW_H

#include <QWidget>
#include <QFileSystemModel>
#include <QListWidgetItem>
#include <QCheckBox>

namespace Ui {
class CWidgetTreeView;
}

class CWidgetTreeView : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetTreeView(QWidget *parent = nullptr);
    ~CWidgetTreeView();

private slots:
    void SlotSliderMoved(int value);
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::CWidgetTreeView *ui;
    QFileSystemModel* m_pFileModel;
    QCheckBox* m_pCheckBoxAll;
};

#endif // WIDGETTREEVIEW_H

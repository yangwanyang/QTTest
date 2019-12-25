#ifndef WIDGETQSS_H
#define WIDGETQSS_H

#include <QWidget>

namespace Ui {
class CWidgetQSS;
}

class CWidgetQSS : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetQSS(QWidget *parent = nullptr);
    ~CWidgetQSS();

private:
    void InitTableWidget();

private slots:

    void on_listWidget_currentRowChanged(int currentRow);

    void on_btnQSSLoad_clicked();

private:
    Ui::CWidgetQSS *ui;
};

#endif // WIDGETQSS_H

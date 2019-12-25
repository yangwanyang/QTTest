#ifndef WIDGETQML_H
#define WIDGETQML_H

#include <QWidget>

namespace Ui {
class CWidgetQML;
}

class CWidgetQML : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetQML(QWidget *parent = nullptr);
    ~CWidgetQML();

private slots:
    void receiveFromQml(int number, QString str);
    void on_pushButton_clicked();

private:
    Ui::CWidgetQML *ui;
};

#endif // WIDGETQML_H

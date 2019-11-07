#ifndef WIDGETPROBLEM_H
#define WIDGETPROBLEM_H

#include <QWidget>

namespace Ui {
class CWidgetProblem;
}

class CWidgetProblem : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetProblem(QWidget *parent = nullptr);
    ~CWidgetProblem();

private:
    void FindMaxSubstring(QString qstrSrc, int &nMaxLength, QString &qstrSubstring);

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

    void on_btnMaxStringAction_clicked();

private:
    Ui::CWidgetProblem *ui;
};

#endif // WIDGETPROBLEM_H

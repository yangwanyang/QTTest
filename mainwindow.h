#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QTableView>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool eventFilter(QObject* o, QEvent* e);
//    void keyPressEvent(QKeyEvent *event);
private slots:
    void on_btnMySQLConn_clicked();

    void on_btnMySQLQuery_clicked();

    void on_btnTableViewInit_clicked();

    void on_btnTableViewGridStyle_clicked();

    void on_btnTableViewAdd_clicked();

    void on_btnTableViewSort_clicked();

private:
    Ui::MainWindow *ui;

    //MySQL
    QSqlDatabase m_sqlDB;
    QSqlQuery m_sqlQuery;

    //QTableView
    QStandardItemModel* m_modelTableView;
};

#endif // MAINWINDOW_H

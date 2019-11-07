#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCheckBox>
#include <QPushButton>
#include <QStylePainter>
#include <QVector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_modelTableView = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMySQLConn_clicked()
{
    m_sqlDB=QSqlDatabase::addDatabase("QODBC");
    m_sqlDB.setHostName("127.0.0.1");
    m_sqlDB.setPort(3306);
    m_sqlDB.setDatabaseName("cjk");
    m_sqlDB.setUserName("root");
    m_sqlDB.setPassword("root");
    if (!m_sqlDB.open())
    {
        QString log = "connect to mysql error. " + m_sqlDB.lastError().text();
        ui->textEditMySQLLog->append(log);
        //qDebug()<<"不能连接 " << "connect to mysql error" << m_sqlDB.lastError().text();
        return ;
    }
    else
    {
        QString log = "connect to mysql OK";
        ui->textEditMySQLLog->append(log);
        //qDebug()<<"连接成功 " << "connect to mysql OK";
    }
}

void MainWindow::on_btnMySQLQuery_clicked()
{
    QString log;
    QSqlQuery query(m_sqlDB);
    QString buf = ui->textEditMySQLBuffer->toPlainText();
    bool flag = query.exec(buf);
    if (!flag)
    {
        log = QStringLiteral("操作失败. ") + query.lastError().text();
        ui->textEditMySQLLog->append(log);
    }
}

void MainWindow::on_btnTableViewInit_clicked()
{
    if(m_modelTableView == nullptr)
    {
        m_modelTableView = new QStandardItemModel();
    }
    m_modelTableView->clear();
    QStringList strList;
    strList << QStringLiteral("姓名") << QStringLiteral("年龄") << QStringLiteral("性别") << QStringLiteral("操作") << QStringLiteral("是否");
    m_modelTableView->setHorizontalHeaderLabels(strList);
    ui->tableView->setModel(m_modelTableView);
    ui->tableView->setSortingEnabled(true);
    ui->tableView_2->setModel(m_modelTableView);
    ui->comboBox->setModel(m_modelTableView);

    //只需要维护m_modelTableView中的数据即可，视图会自行更新
    for(int i=0; i<20; i++)
    {
        m_modelTableView->setItem(i, 0, new QStandardItem("ywy"));
        m_modelTableView->setItem(i, 1, new QStandardItem("20"));
        m_modelTableView->setItem(i, 2, new QStandardItem("man"));
        QPushButton *pBtn = new QPushButton(QStringLiteral("编辑"));
        ui->tableView->setIndexWidget(m_modelTableView->index(m_modelTableView->rowCount() - 1, 3), pBtn);
        QCheckBox *pCBox = new QCheckBox(QStringLiteral("是否"));
        ui->tableView->setIndexWidget(m_modelTableView->index(m_modelTableView->rowCount() - 1, 4), pCBox);
    }

    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignHCenter); //设置垂直表头居中
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter); //设置水平表头居中
    ui->tableView->verticalHeader()->setMinimumWidth(50);

    //表格左上角设置文本，需要QEvent::Paint
    QAbstractButton* btn = ui->tableView->findChild<QAbstractButton*>();
    if (btn)
    {
        btn->setText(QStringLiteral("序号"));
        btn->installEventFilter(this);/*注册事件 eventFilter*/
        QStyleOptionHeader opt;
        opt.text = btn->text();
        QSize s = (btn->style()->sizeFromContents(QStyle::CT_HeaderSection, &opt, QSize(), btn).expandedTo(QApplication::globalStrut()));
        if (s.isValid())
            ui->tableView->verticalHeader()->setMinimumWidth(s.width());
    }
}

bool MainWindow::eventFilter(QObject* o, QEvent* e)
{
    if (e->type() == QEvent::Paint)
    {
        QAbstractButton* btn = qobject_cast<QAbstractButton*>(o);
        if (btn)
        {
            // paint by hand (borrowed from QTableCornerButton)

            QStyleOptionHeader opt;
            opt.init(btn);
            QStyle::State state = QStyle::State_None;
            if (btn->isEnabled())
                state |= QStyle::State_Enabled;
            if (btn->isActiveWindow())
                state |= QStyle::State_Active;
            if (btn->isDown())
                state |= QStyle::State_Sunken;
            opt.state = state;
            opt.rect = btn->rect();
            opt.text = btn->text(); // this line is the only difference to QTableCornerButton

            opt.position = QStyleOptionHeader::OnlyOneSection;
            QStylePainter painter(btn);
            opt.textAlignment = Qt::AlignCenter;
            painter.drawControl(QStyle::CE_Header, opt);
            return true; // eat event

        }
    }
    return QMainWindow::eventFilter(o, e);
    //return false;
}

void MainWindow::on_btnTableViewGridStyle_clicked()
{
    static int nStyle = 0;
    switch(nStyle)
    {
    case Qt::NoPen:
        nStyle =Qt::SolidLine;
        ui->tableView->setGridStyle(Qt::SolidLine);
        break;
    case Qt::SolidLine:
        nStyle =Qt::DashLine;
        ui->tableView->setGridStyle(Qt::DashLine);
        break;
    case Qt::DashLine:
        nStyle =Qt::DotLine;
        ui->tableView->setGridStyle(Qt::DotLine);
        break;
    case Qt::DotLine:
        nStyle =Qt::DashDotLine;
        ui->tableView->setGridStyle(Qt::DashDotLine);
        break;
    case Qt::DashDotLine:
        nStyle =Qt::DashDotDotLine;
        ui->tableView->setGridStyle(Qt::DashDotDotLine);
        break;
    case Qt::DashDotDotLine:
        nStyle =Qt::CustomDashLine;
        ui->tableView->setGridStyle(Qt::CustomDashLine);
        break;
    case Qt::CustomDashLine:
        nStyle =Qt::NoPen;
        ui->tableView->setGridStyle(Qt::NoPen);
        break;
    default:
        break;
    }
}

void MainWindow::on_btnTableViewAdd_clicked()
{
    if(m_modelTableView == nullptr)
    {
        return;
    }
    QStandardItem* item = nullptr;
    for(int i=0; i<10; i++)
    {
        item = new QStandardItem(QString("%1").arg(i));
        m_modelTableView->setItem(i, 0, item);
        item = new QStandardItem(QString("%1").arg(i*2));
        m_modelTableView->setItem(i, 1, item);
        item = new QStandardItem(QString("%1").arg(i*3));
        m_modelTableView->setItem(i, 2, item);
//        QPushButton* btn = new QPushButton("btn");
//        m_modelTableView->setItem(i, 3, btn);

    }
}

void MainWindow::on_btnTableViewSort_clicked()
{
    ui->tableView->setSortingEnabled(!ui->tableView->isSortingEnabled());
}

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//    qDebug() << QString("keyDwon:%1").arg(event->text());
//}

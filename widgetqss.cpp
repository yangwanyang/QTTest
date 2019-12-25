#include "widgetqss.h"
#include "ui_widgetqss.h"
#include <QFile>
#include <QTableWidgetItem>
#include <QLabel>
#include <QDebug>

CWidgetQSS::CWidgetQSS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetQSS)
{
    ui->setupUi(this);

    //加载样式表
    QFile file("../QSS/widgetqss.qss");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        setStyleSheet(qss);
        file.close();
    }
    //InitTable
    InitTableWidget();
}

CWidgetQSS::~CWidgetQSS()
{
    delete ui;
}

void CWidgetQSS::InitTableWidget()
{
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(20);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << QStringLiteral("第一列") << QStringLiteral("第二列") << QStringLiteral("第三列") <<
                                               QStringLiteral("第四列") << QStringLiteral("第五列"));
    for (int i=0; i<20; i++)
    {
        for (int j=0; j<5; j++)
        {
            QString szText = QString("%1%2").arg(i).arg(j);
            QTableWidgetItem *item = new QTableWidgetItem(szText);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(i, j, item);

            QWidget* widget = new QWidget;
            QVBoxLayout* vLayout = new QVBoxLayout;
            QLabel* label = new QLabel(szText);
            label->setAlignment(Qt::AlignCenter);
            widget->setFixedHeight(30);
            widget->setFocusPolicy(Qt::NoFocus);
            widget->setLayout(vLayout);
            vLayout->addWidget(label);
            if (j == 0)
            {
                widget->setProperty("first", "true");
                ui->tableWidget->setCellWidget(i, j, widget);
            }
            else if (j == 4)
            {
                widget->setProperty("last", "true");
                ui->tableWidget->setCellWidget(i, j, widget);
            }
            else
            {
                widget->setProperty("middle", "true");
                ui->tableWidget->setCellWidget(i, j, widget);
            }
        }
    }
}

void CWidgetQSS::on_listWidget_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}

void CWidgetQSS::on_btnQSSLoad_clicked()
{
    //加载样式表
    QFile file("../QSS/widgetqss.qss");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        this->setStyleSheet("");
        this->setStyleSheet(qss);
        file.close();
    }
}

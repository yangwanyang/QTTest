#include "widgettreeview.h"
#include "ui_widgettreeview.h"
#include <QCheckBox>
#include <QScrollBar>
#include <QAbstractSlider>
#include <QDebug>

CWidgetTreeView::CWidgetTreeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetTreeView)
{
    ui->setupUi(this);

    //文件Model
    m_pFileModel = new QFileSystemModel();
    m_pFileModel->setRootPath(QDir::currentPath());
    QModelIndex parentIndex = m_pFileModel->index(QDir::currentPath());
    int numRows = m_pFileModel->rowCount(parentIndex);
    ui->treeView->setModel(m_pFileModel);
    ui->treeView->setRootIndex(m_pFileModel->index(QDir::currentPath()));
//    qDebug() << numRows << QDir::currentPath();

    //表头添加勾选框
    QHeaderView* pHeader = ui->treeWidget->header();
    QWidget* pWidget = static_cast<QWidget*>(pHeader);
    qDebug() << pWidget->geometry();
    m_pCheckBoxAll = new QCheckBox(pWidget);
    m_pCheckBoxAll->setGeometry(4,9,13,13);
    m_pCheckBoxAll->setObjectName("checkBoxAll");
    QTreeView* pTreeView = static_cast<QTreeView*>(ui->treeWidget);
    connect(pTreeView->horizontalScrollBar(), &QAbstractSlider::valueChanged, this, &CWidgetTreeView::SlotSliderMoved);

}

CWidgetTreeView::~CWidgetTreeView()
{
    delete ui;
}

void CWidgetTreeView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int nIndex = ui->listWidget->row(item);
    ui->stackedWidget->setCurrentIndex(nIndex);
}

void CWidgetTreeView::SlotSliderMoved(int value)
{
    qDebug() << value;
    m_pCheckBoxAll->setGeometry(4-value,9,13,13);
}

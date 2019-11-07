#include "widgettreeview.h"
#include "ui_widgettreeview.h"
#include <QDebug>

CWidgetTreeView::CWidgetTreeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetTreeView)
{
    ui->setupUi(this);

    m_pFileModel = new QFileSystemModel();
    m_pFileModel->setRootPath(QDir::currentPath());
    QModelIndex parentIndex = m_pFileModel->index(QDir::currentPath());
    int numRows = m_pFileModel->rowCount(parentIndex);
    ui->treeView->setModel(m_pFileModel);
    ui->treeView->setRootIndex(m_pFileModel->index(QDir::currentPath()));
//    qDebug() << numRows << QDir::currentPath();
}

CWidgetTreeView::~CWidgetTreeView()
{
    delete ui;
}

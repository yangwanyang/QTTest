#include "widgetdrop.h"
#include "ui_widgetdrop.h"
#include <QDebug>
#include <QMimeData>
#include <QDragEnterEvent>

CWidgetDrop::CWidgetDrop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetDrop)
{
    ui->setupUi(this);
    ui->widget->installEventFilter(this);
    ui->widget->setAcceptDrops(true);
    ui->labelInfo->setAcceptDrops(true);
}

CWidgetDrop::~CWidgetDrop()
{
    delete ui;
}
/*
//void CWidgetDrop::dragEnterEvent(QDragEnterEvent *e)
//{
//    if(e->mimeData()->hasFormat("text/uri-list")) //只能打开文本文件
//        e->acceptProposedAction(); //可以在这个窗口部件上拖放对象
//}

//void CWidgetDrop::dropEvent(QDropEvent *e) //释放对方时，执行的操作
//{
//    QList<QUrl> urls = e->mimeData()->urls();
//    if(urls.isEmpty())
//        return ;

//    QString fileName = urls.first().toLocalFile();
//    ui->labelInfo->setText(fileName);

//    foreach (QUrl u, urls) {
//        qDebug()<<u.toString();
//    }
//    qDebug()<< urls.size();

//    if(fileName.isEmpty())
//        return;

//}
*/
bool CWidgetDrop::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->widget)
    {
        if (event->type() == QEvent::DragEnter)
        {
            // [[2]]: 当拖放时鼠标进入label时, label接受拖放的动作
            QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
            dee->acceptProposedAction();
            dee->setDropAction(Qt::MoveAction);
            return true;
        }
        else if (event->type() == QEvent::Drop)
        {
            // [[3]]: 当放操作发生后, 取得拖放的数据
            QDropEvent *de = dynamic_cast<QDropEvent *>(event);
            QList<QUrl> urls = de->mimeData()->urls();
            if (urls.isEmpty()) { return true; }
            QString path = urls.first().toLocalFile();
            ui->labelInfo->setText(path);
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}


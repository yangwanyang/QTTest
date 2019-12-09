#include "widgetevent.h"
#include "ui_widgetevent.h"
#include <QKeyEvent>

CWidgetEvent::CWidgetEvent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetEvent)
{
    ui->setupUi(this);
    ui->plainTextEditLog->setReadOnly(true);
}

CWidgetEvent::~CWidgetEvent()
{
    delete ui;
}

bool CWidgetEvent::event(QEvent *event)
{
    return QWidget::event(event);
}

void CWidgetEvent::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F1)
    {
        ui->plainTextEditLog->appendPlainText(QString("keyDwon:Key_F1"));
        ui->plainTextEditLog->moveCursor(QTextCursor::End);
    }
    if(event->key() == Qt::Key_A)
    {
        ui->plainTextEditLog->appendPlainText(QString("keyDwon:Key_A"));
        ui->plainTextEditLog->moveCursor(QTextCursor::End);
    }
}

void CWidgetEvent::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::RightButton)
    {
        ui->plainTextEditLog->appendPlainText(QString("mousePressEvent:RightButton"));
        ui->plainTextEditLog->moveCursor(QTextCursor::End);
    }
}


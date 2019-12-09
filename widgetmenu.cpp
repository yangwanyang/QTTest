#include "widgetmenu.h"
#include "ui_widgetmenu.h"
#include <QMessageBox>
#include <QStyle>
#include <QDebug>

CWidgetMenu::CWidgetMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetMenu)
{
    ui->setupUi(this);


    m_pMyMenu = new QMenu();
    QAction* pAction1 = new QAction(QStringLiteral("刷新"));
    pAction1->setShortcut(QKeySequence::Refresh);       //快捷键设置
    pAction1->setIcon(style()->standardIcon(QStyle::SP_DirIcon));   //图标设置
    m_pMyMenu->addAction(pAction1);
    connect(pAction1, &QAction::triggered, this, &CWidgetMenu::SlotAction4);

    QAction* pAction2 = new QAction(QStringLiteral("复制"));
    pAction2->setShortcut(QKeySequence::Copy);
    m_pMyMenu->addAction(pAction2);

    QAction* pAction3 = new QAction(QStringLiteral("菜单3"));
    m_pMyMenu->addAction(pAction3);

    QAction* pAction4 = new QAction(QStringLiteral("菜单4"));
    pAction4->setShortcut(QKeySequence::Open);
    m_pMyMenu->addAction(pAction4);
    connect(pAction4, &QAction::triggered, this, &CWidgetMenu::SlotAction4);

    QAction* pAction5_1 = new QAction(QStringLiteral("菜单5-1"));
    m_pMyMenu->addMenu(QStringLiteral("菜单5"))->addAction(pAction5_1);
}

CWidgetMenu::~CWidgetMenu()
{
    delete ui;
}

void CWidgetMenu::mousePressEvent(QMouseEvent *event)
{
    QRect rect(10, 10, 100, 200);
    qDebug() << rect.x()+rect.width() << rect.right();
    if(event->button() == Qt::RightButton && rect.contains(event->pos()))
    {
        m_pMyMenu->exec(event->globalPos());
        event->accept();
    }
}

void CWidgetMenu::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::red);
    painter.drawRect(10, 10, 100, 200);
    painter.drawText(20, 40, QStringLiteral("菜单区域"));


//    QPainter painter(this);
//    painter.setWindow(0, 0, 200, 200);
//    painter.fillRect(0, 0, 200, 200, Qt::red);
}

void CWidgetMenu::SlotAction4()
{
    QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("菜单4"));
}

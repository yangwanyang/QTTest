#include "widgetweb.h"
#include "ui_widgetweb.h"
#include <QWebEngineSettings>

CWidgetWeb::CWidgetWeb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetWeb)
{
    ui->setupUi(this);
    m_pMyWeb = nullptr;
    ui->pushButtonLoad->setEnabled(false);
}

CWidgetWeb::~CWidgetWeb()
{
    m_pMyWeb->deleteLater();
    delete ui;
}

void CWidgetWeb::on_pushButtonLoad_clicked()
{
    QString qstrUrl = ui->lineEditURL->text();
    m_pMyWeb->load(QUrl(qstrUrl));
}

void CWidgetWeb::on_pushButtonInit_clicked()
{
    ui->pushButtonInit->setEnabled(false);
    ui->pushButtonLoad->setEnabled(true);

    m_pMyWeb = new QWebEngineView();
    ui->gridLayoutWeb->addWidget(m_pMyWeb);
//    m_pMyWeb->setZoomFactor(1.5);       //页面缩放系数
    m_pMyWeb->show();
}

void CWidgetWeb::resizeEvent(QResizeEvent *event)
{
    if(m_pMyWeb)
    {
//        m_pMyWeb->resize(this->size());
    }
}

#include "widgettcpclient.h"
#include "ui_widgettcpclient.h"

CWidgetTCPClient::CWidgetTCPClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetTCPClient)
{
    ui->setupUi(this);
    InitSocket();
}

CWidgetTCPClient::~CWidgetTCPClient()
{
    delete ui;
}

void CWidgetTCPClient::InitSocket()
{
    m_pMyClient = new QTcpSocket(this);    //分配空间
    connect(m_pMyClient,SIGNAL(connected()),this,SLOT(oneProcessConnected()));     //连接成功
    connect(m_pMyClient,SIGNAL(readyRead()),this,SLOT(oneProcessReadyRead()));     //读取服务器信息数据
    connect(m_pMyClient,SIGNAL(disconnected()),this,SLOT(oneProcessDisconnected()));       //服务器断开
    connect(m_pMyClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(oneProcessError(QAbstractSocket::SocketError)));     //出错函数
}

void CWidgetTCPClient::on_pushButtonConnect_clicked()
{
    if(ui->pushButtonConnect->text() == QStringLiteral("连接"))
    {
        ui->pushButtonConnect->setText(QStringLiteral("断开"));
        QString serveIP = ui->lineEditSeverIP->text();    //获取服务器IP
        QString servePort = ui->lineEditSeverPort->text();    //获取服务器端口号
        m_pMyClient->connectToHost(QHostAddress(serveIP),servePort.toUShort());   //连接服务器
    }
    else
    {
        ui->pushButtonConnect->setText(QStringLiteral("连接"));
        m_pMyClient->disconnectFromHost();
    }
}
//连接成功函数
void CWidgetTCPClient::oneProcessConnected()
{
    QString msg = QStringLiteral("与服务器连接成功");
    ui->textEditRecv->append(msg);
}

//读取服务器信息函数
void CWidgetTCPClient::oneProcessReadyRead()
{
    QString msg,str1,str2;
    str1 = QStringLiteral("服务器[%1:%2] 说：").arg(m_pMyClient->peerAddress().toString()).arg(m_pMyClient->peerPort());
    while(!m_pMyClient->atEnd())
    {
        str2.append(QString(m_pMyClient->readAll()));
    }
    msg = QString("%1%2").arg(str1).arg(str2);
    ui->textEditRecv->append(msg);
}

//服务器断开函数
void CWidgetTCPClient::oneProcessDisconnected()
{
    QString msg = QStringLiteral("与服务器连接断开");
    ui->textEditRecv->append(msg);
}

//出错函数
void CWidgetTCPClient::oneProcessError(QAbstractSocket::SocketError err)
{
    qDebug() << err;
}

void CWidgetTCPClient::on_pushButtonSend_clicked()
{
    QString msg = ui->textEditSend->toPlainText();
    qint64 ret = m_pMyClient->write(msg.toUtf8());
    if(ret <= 0)
    {
        return;
    }
    ui->textEditSend->clear();
}

#include "widgettcpserver.h"
#include "ui_widgettcpserver.h"

#define MAXNUM 100

CWidgetTCPServer::CWidgetTCPServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetTCPServer)
{
    ui->setupUi(this);
    InitServer();
}

CWidgetTCPServer::~CWidgetTCPServer()
{
    delete ui;
}

void CWidgetTCPServer::InitServer()
{
    m_pMyServer = new QTcpServer(this);
}

void CWidgetTCPServer::on_pushButtonBound_clicked()
{
    //方法一：通过程序遍历网卡IP
    QString myAddr;
//    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();       //返回所有IP地址，然后进行遍历
//    for(int i=0;i<ipAddressesList.length();i++)
//    {
//        QHostAddress  addr = ipAddressesList.at(i);
//        ui->textEditRecv->append(addr.toString());      //打印返回信息
//        if(addr.toString().contains("192."))      //筛选
//        {
//            myAddr = addr.toString();
//            ui->textEditRecv->append("***************");
//            ui->textEditRecv->append(myAddr);
//            break;
//        }
//    }
//    ui->lineEditSeverIP->setText(myAddr);
    ui->lineEditSeverPort->setText("10086");

    //方法二：手动设置IP
    myAddr = ui->lineEditSeverIP->text();     //手动输入IP到edit框
    QString myPort = ui->lineEditSeverPort->text();       //手动设置端口
    QString msg;
    bool ret = m_pMyServer->listen(QHostAddress::AnyIPv4,myPort.toUShort());      //服务器监听绑定
    if(!ret)
    {
        msg = QStringLiteral("绑定失败\n");
    }
    else
    {
        msg = QStringLiteral("绑定成功\n");
        ui->pushButtonBound->setEnabled(false);
    }
    ui->textEditRecv->append(msg);       //将信息显示在消息框

    m_pMyServer->setMaxPendingConnections(MAXNUM);     //设置监听数量
    connect(m_pMyServer,SIGNAL(newConnection()),this,SLOT(oneProcessNewConnection()));     //建立新的连接信号
    connect(m_pMyServer,SIGNAL(acceptError(QAbstractSocket::SocketError)),this,SLOT(oneProcessAcceptError(QAbstractSocket::SocketError))); //错误处理
}

//建立连接信号函数
void CWidgetTCPServer::oneProcessNewConnection()
{
    m_pClient = m_pMyServer->nextPendingConnection();     //客户端的连接，获取客户端描述符
    m_arrayClient.append(m_pClient);

    qDebug() << "QTcpSocket *client->peerAddress() : " << m_pClient->peerAddress().toString();
    QString msg = QStringLiteral("客户端[%1:%2] 连入！\n").arg(m_pClient->peerAddress().toString()).arg(m_pClient->peerPort());
    ui->textEditRecv->append(msg);

    QString buf = QString("%1:%2").arg(m_pClient->peerAddress().toString()).arg(m_pClient->peerPort());
    ui->comboBoxClientIP->addItem(buf);
    int index = ui->comboBoxClientIP->findText(buf);
    ui->comboBoxClientIP->setItemData(index, QVariant(m_pClient->peerPort()));

    //客户端断开
    connect(m_pClient,SIGNAL(disconnected()),this,SLOT(oneProcessDisconnected()));
    //读取客户端内容
    connect(m_pClient,SIGNAL(readyRead()),this,SLOT(oneProcessReadyRead()));
    //客户端的连入
    connect(m_pClient,SIGNAL(connected()),this,SLOT(oneProcessConnected()));
}
//错误处理函数
void CWidgetTCPServer::oneProcessAcceptError(QAbstractSocket::SocketError err)
{
    qDebug() << err;
}

//客户端断开函数
void CWidgetTCPServer::oneProcessDisconnected()
{
    QTcpSocket *client = static_cast<QTcpSocket *>(this->sender());      //强转TCP类型
    QString msg = QStringLiteral("客户端[%1:%2] 退出！\n").arg(client->peerAddress().toString()).arg(client->peerPort());
    ui->textEditRecv->append(msg);        //显示断开信息

    //遍历删除对应客户端
    for(int i=0;i<m_arrayClient.length();i++)
    {
        if(m_arrayClient.at(i)->peerAddress() == client->peerAddress())
        {
            if(m_arrayClient.at(i)->peerPort() == client->peerPort())
            {
                m_arrayClient.removeAt(i);
                QString buf = QString("%1:%2").arg(client->peerAddress().toString()).arg(client->peerPort());
                int index = ui->comboBoxClientIP->findText(buf);
                ui->comboBoxClientIP->removeItem(index);
                break;
            }
        }
    }
}

//读取客户端内容函数
void CWidgetTCPServer::oneProcessReadyRead()
{
    QTcpSocket *client = static_cast<QTcpSocket *>(this->sender());      //强转TCP类型
    QString str1 = QStringLiteral("客户端[%1:%2] 说：").arg(client->peerAddress().toString()).arg(client->peerPort());
    QString msg;
    QString str2;
    while(!client->atEnd())     //不到末尾是进行读取内容
    {
        msg.append(QString(client->readAll()));
    }
    str2 = QString("%1%2").arg(str1).arg(msg);
    ui->textEditRecv->append(str2);       //将读取客户端的内容显示在edit信息框
}

void CWidgetTCPServer::oneProcessConnected()
{
    QTcpSocket *client = static_cast<QTcpSocket *>(this->sender());
    QString msg = QStringLiteral("客户端[%1:%2] 连入！").arg(client->peerAddress().toString()).arg(client->peerPort());
    ui->textEditRecv->append(msg);
    ui->comboBoxClientIP->addItem(client->peerAddress().toString());
    int index = ui->comboBoxClientIP->findText(client->peerAddress().toString());
    ui->comboBoxClientIP->setItemData(index, QVariant(client->peerPort()));
}

//点击槽函数实现，发送信息给客户端
void CWidgetTCPServer::on_pushButtonSend_clicked()
{
    QString ip = ui->comboBoxClientIP->currentText().mid(0, ui->comboBoxClientIP->currentText().indexOf(":"));    //获取IP
    QString port = ui->lineEditClientPort->text();    //获取端口号
    if(ui->comboBoxClientIP->currentText() == QStringLiteral("广播"))
    {
        for(int i=0;i<m_arrayClient.length();i++)
        {
            QString msg = ui->textEditSend->toPlainText();   //获取发送消息
            m_arrayClient.at(i)->write(msg.toUtf8());     //将消息发送出去
        }
        ui->textEditSend->clear();       //将消息框清空
    }
    else
    {
        //遍历查找对应的客户
        for(int i=0;i<m_arrayClient.length();i++)
        {
            if(m_arrayClient.at(i)->peerAddress().toString() == ip)
            {
                if(m_arrayClient.at(i)->peerPort() == port.toUInt())
                {
                    QString msg = ui->textEditSend->toPlainText();   //获取发送消息
                    m_arrayClient.at(i)->write(msg.toUtf8());     //将消息发送出去
                    ui->textEditSend->clear();       //将消息框清空
                    break;
                }
            }
        }
    }
}

void CWidgetTCPServer::on_comboBoxClientIP_currentIndexChanged(int index)
{
    QVariant v = ui->comboBoxClientIP->itemData(index);
    ui->lineEditClientPort->setText(v.toString());
}

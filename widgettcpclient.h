#ifndef WIDGETTCPCLIENT_H
#define WIDGETTCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkInterface>

namespace Ui {
class CWidgetTCPClient;
}

class CWidgetTCPClient : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetTCPClient(QWidget *parent = nullptr);
    ~CWidgetTCPClient();

private slots:
    void oneProcessConnected();     //连接成功函数
    void oneProcessReadyRead();     //读取服务器信息函数
    void oneProcessDisconnected();      //服务器断开函数
    void oneProcessError(QAbstractSocket::SocketError err);     //出错函数
    void on_pushButtonConnect_clicked();

    void on_pushButtonSend_clicked();

private:
    void InitSocket();      //初始化客户端函数
private:
    Ui::CWidgetTCPClient *ui;
    QTcpSocket *m_pMyClient;    //定义客户端对象
};

#endif // WIDGETTCPCLIENT_H

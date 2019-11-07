#ifndef WIDGETTCPSERVER_H
#define WIDGETTCPSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>

namespace Ui {
class CWidgetTCPServer;
}

class CWidgetTCPServer : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetTCPServer(QWidget *parent = nullptr);
    ~CWidgetTCPServer();

private slots:
    void oneProcessNewConnection();     //新的连接信号函数
    void oneProcessAcceptError(QAbstractSocket::SocketError err);       //错误处理函数
    void oneProcessDisconnected();      //客户端断开函数
    void oneProcessReadyRead();     //读取客户端内容
    void oneProcessConnected();     //客户端连入函数
    void on_pushButtonBound_clicked();

    void on_pushButtonSend_clicked();

    void on_comboBoxClientIP_currentIndexChanged(int index);

private:
    void InitServer();      //初始化服务器

private:
    Ui::CWidgetTCPServer *ui;
    QTcpServer *m_pMyServer;   //定义服务对象
    QList <QTcpSocket *> m_arrayClient;   //保存客户端
    QTcpSocket *m_pClient;     //定义客户端描述符
};

#endif // WIDGETTCPSERVER_H

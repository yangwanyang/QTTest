#include "widgethttp.h"
#include "ui_widgethttp.h"
#include <urlmon.h>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>

CBindCallback::CBindCallback(void)
{
}

CBindCallback::~CBindCallback(void)
{
}

//////仅实现OnProgress成员即可
LRESULT CBindCallback::OnProgress(ULONG ulProgress,
                                  ULONG ulProgressMax,
                                  ULONG ulSatusCode,
                                  LPCWSTR szStatusText)
{
    QString szBuf;
    szBuf = QStringLiteral("文件总大小ulProgressMax:%1KB--文件已下载大小ulProgress:%2KB--状态值ulSatusCode:%3--szStatusText:%4")
            .arg(ulProgressMax/1024).arg(ulProgress/1024).arg(ulSatusCode).arg(szStatusText);
    qDebug() << szBuf;
    return S_OK;
    //停止下载
    //return E_ABORT;
}



CWidgetHttp::CWidgetHttp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetHttp)
{
    ui->setupUi(this);
}

CWidgetHttp::~CWidgetHttp()
{
    delete ui;
}

void CWidgetHttp::on_btnLoad_clicked()
{
    QString qstrURL = ui->lineEditURL->text();
    QString qstrLocalPath = ui->lineEditLocalPath->text();
    QStringList qstrURLList;
    QStringList qstrLocalPathList;
    qstrURLList << "http://192.168.43.159:2580/XSendfile/RjovSUFMaWdodFBhdGgvMTUxMDM4NDAwMDE3MjM2NjA0LzIwMTkxMDIzL0JGNjEzNzkxOEQ1RTQ2N0Y5MEQ2RDJCREQxMDQ0QjBGLzIwMTkxMDIzMTY0NjAxX1VQMDMzOF9CRjYxMzc5MThENUU0NjdGOTBENkQyQkREMTA0NEIwRi5qcGc="
                << "http://192.168.43.159:2580/XSendfile/RjovSUFMaWdodFBhdGgvMTUxMDM4NDAwMDE3MjM2NjA0LzIwMTkxMDIzL0JGNjEzNzkxOEQ1RTQ2N0Y5MEQ2RDJCREQxMDQ0QjBGLzIwMTkxMDIzMTY0NjAyX1VQMDMzN19CRjYxMzc5MThENUU0NjdGOTBENkQyQkREMTA0NEIwRi5qcGc="
                << "http://192.168.43.159:2580/XSendfile/RjovSUFMaWdodFBhdGgvMTUxMDM4NDAwMDE3MjM2NjA0LzIwMTkxMDIzLzQ2OERFMDA1QzBDQTQzNEI5Mzk2MDNEOUFBRTQ1OTc5LzIwMTkxMDIzMTY0MjA1X1VQMDM0Rl80NjhERTAwNUMwQ0E0MzRCOTM5NjAzRDlBQUU0NTk3OS5qcGc="
                << "http://192.168.43.159:2580/XSendfile/RjovSUFMaWdodFBhdGgvMTUxMDM4NDAwMDE3MjM2NjA0LzIwMTkxMDIzL0M2MkNDQTQyMDY5MDQ1OUJBOTA5Mzg3QTdGMTJBNTIyLzIwMTkxMDIzMTYzNzE3X1VQMDM0Nl9DNjJDQ0E0MjA2OTA0NTlCQTkwOTM4N0E3RjEyQTUyMi5qcGc="
                << "http://192.168.43.159:2580/XSendfile/RjovSUFMaWdodFBhdGgvMTUxMDM4NDAwMDE3MjM2NjA0LzIwMTkxMDIzL0M2MkNDQTQyMDY5MDQ1OUJBOTA5Mzg3QTdGMTJBNTIyLzIwMTkxMDIzMTYzNzE5X1VQMDM0NF9DNjJDQ0E0MjA2OTA0NTlCQTkwOTM4N0E3RjEyQTUyMi5qcGc="
                << "http://192.168.43.159:2580/XSendfile/RjovSUFMaWdodFBhdGgvMTUxMDM4NDAwMDE3MjM2NjA0LzIwMTkxMDIzL0M2MkNDQTQyMDY5MDQ1OUJBOTA5Mzg3QTdGMTJBNTIyLzIwMTkxMDIzMTYzNzIxX1VQMDM0M19DNjJDQ0E0MjA2OTA0NTlCQTkwOTM4N0E3RjEyQTUyMi5qcGc="
                << "http://192.168.43.159:2580/XSendfile/RjovSUFMaWdodFBhdGgvMTUxMDM4NDAwMDE3MjM2NjA0LzIwMTkxMDIzL0MwRDE5MTYxOUNGNjQwNDk4MDNDM0M3NkFDRkVCOTVFLzIwMTkxMDIzMTYzMDI4X1VQMDMzNl9DMEQxOTE2MTlDRjY0MDQ5ODAzQzNDNzZBQ0ZFQjk1RS5qcGc=";
    qstrLocalPathList << "C:/Users/aa/Desktop/1.jpg"
                      << "C:/Users/aa/Desktop/2.jpg"
                      << "C:/Users/aa/Desktop/3.jpg"
                      << "C:/Users/aa/Desktop/4.jpg"
                      << "C:/Users/aa/Desktop/5.jpg"
                      << "C:/Users/aa/Desktop/6.jpg"
                      << "C:/Users/aa/Desktop/7.jpg";
//    for(int i=0; i<qstrURLList.size(); i++)
    {
        QString szRand = QString("?skq=%1").arg(GetTickCount());
        qstrURL += szRand;
        qDebug() << qstrURL;
        QDateTime t1 = QDateTime::currentDateTime();
        LRESULT lres = URLDownloadToFile(nullptr, qstrURL.toStdWString().c_str(), qstrLocalPath.toStdWString().c_str(), 0, &cBindCallback);
//        LRESULT lres = URLDownloadToFile(nullptr, qstrURLList[i].toStdWString().c_str(), qstrLocalPathList[i].toStdWString().c_str(), 0, nullptr);
        QDateTime t2 = QDateTime::currentDateTime();
        ui->textEditLog->append(QStringLiteral("用时:%1毫秒-返回:").arg(t1.msecsTo(t2)).arg(lres));
        if(lres == 0)
        {
            ui->textEditLog->append(QStringLiteral("succ"));
        }
        else
        {
            ui->textEditLog->append(QStringLiteral("fail"));
        }
    }
}

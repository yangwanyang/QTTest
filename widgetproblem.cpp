#include "widgetproblem.h"
#include "ui_widgetproblem.h"

CWidgetProblem::CWidgetProblem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetProblem)
{
    ui->setupUi(this);
}

CWidgetProblem::~CWidgetProblem()
{
    delete ui;
}

void CWidgetProblem::on_listWidget_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}

/******************************* 求最大子字符串 ***********************************/
void CWidgetProblem::on_btnMaxStringAction_clicked()
{
    QString qstrSrc = ui->lineEditMaxStringText->text();
    if (qstrSrc.length() <= 0)
        return;
    int nMaxLength = 0;
    QString qstrSubstring = "";
    FindMaxSubstring(qstrSrc, nMaxLength, qstrSubstring);
    QString qstrBuf = QStringLiteral("[%1]最大长度:%2,最长字符串:%3").arg(qstrSrc).arg(nMaxLength).arg(qstrSubstring);
    ui->textEditMaxStringOutput->append(qstrBuf);
}

void CWidgetProblem::FindMaxSubstring(QString qstrSrc, int &nMaxLength, QString &qstrSubstring)
{
    //滑块思想
    //出现重复子字符的头后移，不出现重复子字符的尾后移
    int nHead = 0;
    int nEnd = 0;
    QString qstrTemp ="";
    while (nEnd < qstrSrc.length())
    {
        if (qstrTemp.indexOf(qstrSrc[nEnd]) < 0)
        {
            qstrTemp = qstrSrc.mid(nHead, nEnd-nHead+1);
            if (qstrSubstring.length() < qstrTemp.length())
            {
                qstrSubstring = qstrTemp;
                nMaxLength = qstrTemp.length();
            }
            nEnd++;
        }
        else
        {
            nHead++;
            qstrTemp = qstrSrc.mid(nHead, nEnd-nHead);
        }
    }
}

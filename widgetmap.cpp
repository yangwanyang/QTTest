#include "widgetmap.h"
#include "ui_widgetmap.h"
#include <QInputDialog>

CWidgetMap::CWidgetMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetMap)
{
    ui->setupUi(this);
    Init();
}

CWidgetMap::~CWidgetMap()
{
    delete m_pWebChannel;
    m_pWebChannel = nullptr;
//    delete m_pWebBaidu;
    delete ui;
}

void CWidgetMap::Init()
{
    m_pMyWebChannel = new CMyWebChannel();
    connect(m_pMyWebChannel, &CMyWebChannel::SignalGetCoordinates, this, &CWidgetMap::SlotGetCoordinates);


    m_pWebBaidu = new QWebEngineView(ui->tabBaidu);
    //定义QWebChannel负责
    m_pWebChannel = new QWebChannel(this);
    //QWebChannel对Widget类，注册一个person的通信介质
    //在js文件中person负责成为window.bridge
    //在this中也就是Widget类注册channel，channel访问的位Widget下的槽函数。
    m_pWebChannel->registerObject(QString("person"),m_pMyWebChannel);
    //webenginePage加载Channel功能
    m_pWebBaidu->page()->setWebChannel(m_pWebChannel);

    ui->gridLayoutWeb->addWidget(m_pWebBaidu);
    m_pWebBaidu->show();
    m_pWebBaidu->load(QUrl("file:///E:/ywy/work/QT/test/QTTest/QtBaiduMap.html"));
//    m_pWebBaidu->load(QUrl(QStringLiteral("file:///E:/ywy/work/project/智能监控/src/CRST/CRGISEmapCtrl/HtmlCtrl/html/mapabc/index.html")));
}

void CWidgetMap::on_btnJavaScript_clicked()
{
    bool isOK;
    QString text = QInputDialog::getText(this, "Insert",
                                             "Please input new data:",
                                             QLineEdit::Normal,
                                             "",
                                             &isOK);
    QString cmd = QString("JavaScriptTest(\"%1\")").arg(text);
    m_pWebBaidu->page()->runJavaScript(cmd);
}

void CWidgetMap::SlotGetCoordinates(QString lng, QString lat)
{
    ui->lineEditLat->setText(lat);
    ui->lineEditLng->setText(lng);
}

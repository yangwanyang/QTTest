﻿#include "widgetqml.h"
#include "ui_widgetqml.h"
#include <QUrl>
#include <QQuickItem>
#include <string>
#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>

CWidgetQML::CWidgetQML(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetQML)
{
    ui->setupUi(this);

    QUrl source(QUrl::fromLocalFile(":/qml/MyQML.qml"));
    ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->quickWidget->setSource(source);
    //ui->quickWidget->setClearColor(QColor(Qt::transparent));

    // QML 与 Qt Widgets 通信
//    QObject *pRoot = static_cast<QObject*>(ui->quickWidget->rootObject());
//    if (pRoot != nullptr)
//    {
//        connect(pRoot, SIGNAL(qmlSignal(int, QString)), this, SLOT(receiveFromQml(int, QString)));
//        connect(ui->pushButton, SIGNAL(clicked(bool)), pRoot, SIGNAL(cSignal()));
//    }
}

CWidgetQML::~CWidgetQML()
{
    delete ui;
}

void CWidgetQML::on_pushButton_clicked()
{
//    QDomDocument doc;
//    QFile file("C:/Users/aa/Desktop/aa.xml");
//    if(file.open(QIODevice::ReadWrite | QIODevice::Text))
//    {
        /*
        QTextStream floStream(&file);
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        floStream.setCodec(codec);
        QString xmlDataStr = floStream.readAll();
        */
//        if(doc.setContent(&file))
//        {
//            QDomElement root = doc.documentElement();
//            QDomNode node = root.firstChild();
//            while(!node.isNull())
//            {
//                qDebug() << node.nodeName();
//                node.setNodeValue("asd");
//                node = node.nextSibling();
//            }
//            QTextStream out(&file);
//            doc.save(out, 4);
//        }
//        file.close();

//        QFile file1("C:/Users/aa/Desktop/aa.xml");
//        if(file1.open(QIODevice::ReadWrite | QIODevice::Text))
//        {
//            QTextStream out(&file1);
//            doc.save(out, 4);
//            file1.close();
//        }
//    }
}

void CWidgetQML::receiveFromQml(int number, QString str)
{
    ui->textEdit->append(QString::number(number, 10));
    ui->textEdit->append(str);
}

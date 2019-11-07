#ifndef WIDGETMAP_H
#define WIDGETMAP_H

#include <QWidget>
#include <QWebEngineView>
#include <QWebChannel>
#include "mywebchannel.h"

namespace Ui {
class CWidgetMap;
}

class CWidgetMap : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetMap(QWidget *parent = nullptr);
    ~CWidgetMap();


    void Init();


private slots:
    void SlotGetCoordinates(QString lng, QString lat);
    void on_btnJavaScript_clicked();

private:
    Ui::CWidgetMap *ui;
    QWebEngineView* m_pWebBaidu;
    QWebChannel *m_pWebChannel;
    CMyWebChannel *m_pMyWebChannel;
};

#endif // WIDGETMAP_H

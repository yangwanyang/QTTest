#ifndef WIDGETWEB_H
#define WIDGETWEB_H

#include <QWidget>
#include <QWebEngineView>

namespace Ui {
class CWidgetWeb;
}

class CWidgetWeb : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetWeb(QWidget *parent = nullptr);
    ~CWidgetWeb();

    void resizeEvent(QResizeEvent *event);
private slots:
    void on_pushButtonLoad_clicked();

    void on_pushButtonInit_clicked();

private:
    Ui::CWidgetWeb *ui;
    QWebEngineView* m_pMyWeb;
};

#endif // WIDGETWEB_H

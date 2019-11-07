#ifndef WIDGETHTTP_H
#define WIDGETHTTP_H

#include <QWidget>
#include <urlmon.h>

namespace Ui {
class CWidgetHttp;
}

class CBindCallback : public IBindStatusCallback
{
public:
    CBindCallback(void);
    ~CBindCallback(void);
    //接受显示进度窗口的句柄
    //CUrlDownloadToFileCallbackTestDlg* m_pdlg;

    //IBindStatusCallback的方法。除了OnProgress     外的其他方法都返回E_NOTIMPL
    STDMETHOD(OnStartBinding)
        (DWORD dwReserved,
        IBinding __RPC_FAR *pib)
    { return E_NOTIMPL; }

    STDMETHOD(GetPriority)
        (LONG __RPC_FAR *pnPriority)
    { return E_NOTIMPL; }

    STDMETHOD(OnLowResource)
        (DWORD reserved)
    { return E_NOTIMPL; }

    //OnProgress在这里
    STDMETHOD(OnProgress)
        (ULONG ulProgress,
        ULONG ulProgressMax,
        ULONG ulStatusCode,
        LPCWSTR wszStatusText);

    STDMETHOD(OnStopBinding)
        (HRESULT hresult,
        LPCWSTR szError)
    { return E_NOTIMPL; }

    STDMETHOD(GetBindInfo)
        (DWORD __RPC_FAR *grfBINDF,
        BINDINFO __RPC_FAR *pbindinfo)
    { return E_NOTIMPL; }

    STDMETHOD(OnDataAvailable)
        (DWORD grfBSCF,
        DWORD dwSize,
        FORMATETC __RPC_FAR *pformatetc,
        STGMEDIUM __RPC_FAR *pstgmed)
    { return E_NOTIMPL; }

    STDMETHOD(OnObjectAvailable)
        (REFIID riid,
        IUnknown __RPC_FAR *punk)
    { return E_NOTIMPL; }

    // IUnknown方法.IE 不会调用这些方法的

    STDMETHOD_(ULONG, AddRef)()
    { return 0; }

    STDMETHOD_(ULONG, Release)()
    { return 0; }

    STDMETHOD(QueryInterface)
        (REFIID riid,
        void __RPC_FAR *__RPC_FAR *ppvObject)
    { return E_NOTIMPL; }
};

class CWidgetHttp : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetHttp(QWidget *parent = nullptr);
    ~CWidgetHttp();

private slots:
    void on_btnLoad_clicked();

private:
    Ui::CWidgetHttp *ui;
    CBindCallback cBindCallback;
};

#endif // WIDGETHTTP_H

#ifndef CMYWEBCHANNEL_H
#define CMYWEBCHANNEL_H

#include <QObject>

class CMyWebChannel : public QObject
{
    Q_OBJECT
public:
    explicit CMyWebChannel(QObject *parent = nullptr);

signals:
    void SignalGetCoordinates(QString lng, QString lat);

public slots://与地图JS交互的槽函数必须是public
    void GetCoordinates(QString lng, QString lat);
};

#endif // CMYWEBCHANNEL_H

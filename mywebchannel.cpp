#include "mywebchannel.h"

CMyWebChannel::CMyWebChannel(QObject *parent) : QObject(parent)
{

}
void CMyWebChannel::GetCoordinates(QString lng, QString lat)
{
    emit SignalGetCoordinates(lng, lat);
}

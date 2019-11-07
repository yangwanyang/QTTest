#ifndef WIDGETMEDIA_H
#define WIDGETMEDIA_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>

namespace Ui {
class CWidgetMedia;
}

class CWidgetMedia : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetMedia(QWidget *parent = nullptr);
    ~CWidgetMedia();

private slots:
    void DurationChanged(qint64 duration);
    void PositionChanged(qint64 progress);
    void SetState(QMediaPlayer::State state);
    void Seek(int seconds);
    void on_pushButtonLoad_clicked();

    void on_pushButtonInit_clicked();

    void on_pushButtonOpen_clicked();

private:
    Ui::CWidgetMedia *ui;
    QMediaPlayer *m_pMyPlayer;
    QVideoWidget *m_pVideoWidget = nullptr;
    QMediaPlaylist *m_playlist = nullptr;
    qint64  m_duration;      //总时长
    bool    m_bPlaying;      //是否正在在播放
    QMediaPlayer::State m_state;    //视频播放状态
};

#endif // WIDGETMEDIA_H

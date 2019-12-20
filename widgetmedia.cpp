#include "widgetmedia.h"
#include "ui_widgetmedia.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QTime>
#include <QStyle>

//Qt5.13 media与web可以同时实例化使用，低版本在debug下运行实例化会报错。
//音视频文件信息获取(如:视频总时长)可以用第三方库ffmpeg，QT的QMediaPlayer不好用

CWidgetMedia::CWidgetMedia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetMedia)
{
    ui->setupUi(this);
    ui->pushButtonLoad->setEnabled(false);
    ui->pushButtonOpen->setEnabled(false);
//    on_pushButtonInit_clicked();
    m_bPlaying = false;
    ui->pushButtonLoad->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

CWidgetMedia::~CWidgetMedia()
{
    delete ui;
}

void CWidgetMedia::on_pushButtonLoad_clicked()
{
    if (!m_bPlaying)
    {
        m_bPlaying = true;
        m_pMyPlayer->play();
        ui->pushButtonLoad->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
    else
    {
        m_bPlaying = false;
        m_pMyPlayer->pause();
        ui->pushButtonLoad->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void CWidgetMedia::on_pushButtonInit_clicked()
{
    ui->pushButtonOpen->setEnabled(true);
    ui->pushButtonInit->setEnabled(false);

    //play
    m_pMyPlayer = new QMediaPlayer(this);
    m_pMyPlayer->setAudioRole(QAudio::VideoRole);

    //playlist
    m_playlist = new QMediaPlaylist();
//    m_pMyPlayer->setPlaylist(m_playlist);

    //video widget
    m_pVideoWidget = new QVideoWidget(this);
    m_pVideoWidget->setStyleSheet("background-color:#000000");
    m_pVideoWidget->show();
    m_pMyPlayer->setVideoOutput(m_pVideoWidget);

    ui->gridLayoutMedia->addWidget(m_pVideoWidget);


    connect(m_pMyPlayer, &QMediaPlayer::durationChanged, this, &CWidgetMedia::DurationChanged);
    connect(m_pMyPlayer, &QMediaPlayer::positionChanged, this, &CWidgetMedia::PositionChanged);
    connect(m_pMyPlayer, &QMediaPlayer::stateChanged, this, &CWidgetMedia::SetState);

    connect(ui->hSlider, &QSlider::sliderMoved, this, &CWidgetMedia::Seek);
}

void CWidgetMedia::on_pushButtonOpen_clicked()
{
    m_playlist->clear();
    QList<QUrl> listUrl;
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Files"));
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
    if(fileDialog.exec() == QDialog::Accepted)
    {
//        qDebug() << fileDialog.selectedUrls();
//        addToPlaylist(fileDialog.selectedUrls());
        listUrl = fileDialog.selectedUrls();
    }
    if(listUrl.size() > 0)
    {
        ui->lineEditURL->setText(listUrl[0].toString());
//        m_playlist->addMedia(listUrl[0]);
        m_pMyPlayer->setMedia(listUrl[0]);
    }
    ui->pushButtonLoad->setEnabled(true);
}

void CWidgetMedia::DurationChanged(qint64 duration)
{
    //视频总时长  毫秒
    m_duration = duration / 1000;
    ui->hSlider->setMaximum(static_cast<int>(m_duration));
}

void CWidgetMedia::PositionChanged(qint64 progress)
{
    //视频播放进度  毫秒(约1秒1个信号)
    if (!ui->hSlider->isSliderDown())
        ui->hSlider->setValue(static_cast<int>(progress / 1000));

    int second = static_cast<int>(progress / 1000);
    QString tStr;
    if (second || m_duration)
    {
        QTime currentTime((second / 3600) % 60, (second / 60) % 60,
            second % 60, (second * 1000) % 1000);
        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60,
            m_duration % 60, (m_duration * 1000) % 1000);
        QString format = "mm:ss";
        if (m_duration > 3600)
            format = "hh:mm:ss";
        tStr = currentTime.toString(format) + " / " + totalTime.toString(format);
    }
    ui->labelTime->setText(tStr);
}

void CWidgetMedia::SetState(QMediaPlayer::State state)
{
    //视频状态发生改变(如:视频播放完停止)
    if (m_state != state)
    {
        m_state = state;

        switch (state)
        {
        case QMediaPlayer::StoppedState:
            ui->pushButtonLoad->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
        case QMediaPlayer::PlayingState:
            ui->pushButtonLoad->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
            break;
        case QMediaPlayer::PausedState:
            ui->pushButtonLoad->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
        }
    }
}

void CWidgetMedia::Seek(int seconds)
{
    //拖动视频进度条
    m_pMyPlayer->setPosition(seconds * 1000);
}

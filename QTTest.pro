#-------------------------------------------------
#
# Project created by QtCreator 2019-08-28T15:52:28
#
#-------------------------------------------------

QT       += core gui sql
QT  += multimedia multimediawidgets
QT  += webenginewidgets webchannel webengine
QT  += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mywebchannel.cpp \
    widgetdrop.cpp \
    widgetevent.cpp \
    widgethttp.cpp \
    widgetmap.cpp \
    widgetmenu.cpp \
    widgetproblem.cpp \
    widgettcpclient.cpp \
    widgettcpserver.cpp \
    widgettreeview.cpp \
    widgetweb.cpp \
    widgetmedia.cpp

HEADERS += \
        mainwindow.h \
    mywebchannel.h \
    widgetdrop.h \
    widgetevent.h \
    widgethttp.h \
    widgetmap.h \
    widgetmenu.h \
    widgetproblem.h \
    widgettcpclient.h \
    widgettcpserver.h \
    widgettreeview.h \
    widgetweb.h \
    widgetmedia.h

FORMS += \
        mainwindow.ui \
    widgetdrop.ui \
    widgetevent.ui \
    widgethttp.ui \
    widgetmap.ui \
    widgetmenu.ui \
    widgetproblem.ui \
    widgettcpclient.ui \
    widgettcpserver.ui \
    widgettreeview.ui \
    widgetweb.ui \
    widgetmedia.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.17763.0/um/x86/' -lUrlmon

INCLUDEPATH += 'C:/Program Files (x86)/Windows Kits/10/Include/10.0.17763.0/um'
DEPENDPATH += 'C:/Program Files (x86)/Windows Kits/10/Include/10.0.17763.0/um'

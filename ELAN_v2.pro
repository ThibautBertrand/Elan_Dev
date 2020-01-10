#-------------------------------------------------
#
# Project created by QtCreator 2020-01-06T14:40:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ELAN_v2
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


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    CentralBottomLayer.cpp \
    CentralMiddleLayer.cpp \
    CentralTopLayer.cpp \
    PlotGeneration.cpp \
    qcustomplot.cpp \
    ScaleWindow.cpp \
    SettingWindow.cpp \
    Wrapper.cpp \
    Cursor.cpp

HEADERS += \
        MainWindow.h \
    CentralBottomLayer.h \
    CentralMiddleLayer.h \
    CentralTopLayer.h \
    PlotGeneration.h \
    qcustomplot.h \
    ScaleWindow.h \
    SettingWindow.h \
    Wrapper.h \
    Cursor.h

FORMS += \
        MainWindow.ui \
    ScaleWindow.ui \
    SettingWindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ELAN_GIT/Ubuntu_18.x86_64/lib/release/ -lelanfile
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ELAN_GIT/Ubuntu_18.x86_64/lib/debug/ -lelanfile
else:unix: LIBS += -L$$PWD/../ELAN_GIT/Ubuntu_18.x86_64/lib/ -lelanfile

INCLUDEPATH += $$PWD/../ELAN_GIT/Ubuntu_18.x86_64/include
DEPENDPATH += $$PWD/../ELAN_GIT/Ubuntu_18.x86_64/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ELAN_GIT/Ubuntu_18.x86_64/lib/release/libelanfile.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ELAN_GIT/Ubuntu_18.x86_64/lib/debug/libelanfile.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ELAN_GIT/Ubuntu_18.x86_64/lib/release/elanfile.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ELAN_GIT/Ubuntu_18.x86_64/lib/debug/elanfile.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ELAN_GIT/Ubuntu_18.x86_64/lib/libelanfile.a

#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T11:28:54
#
#-------------------------------------------------

QT       += core gui widgets network
QT += multimedia

TARGET = Bomberman
TEMPLATE = app

SOURCES += main.cpp\
	mainwindow.cpp \
	windowstatistics.cpp \
    paramwindows.cpp \
    launchsologame.cpp \
    widgetchat.cpp \
    help.cpp \
    eltdecor.cpp \
    eltbomb.cpp \
    eltfixedbrick.cpp \
    elttempbrick.cpp \
    eltplayer.cpp \
    eltbrick.cpp \
    eltbackground.cpp \
    eltfactory.cpp \
    eltmobil.cpp \
    eltbase.cpp \
	bmerror.cpp \
	bmerrormanager.cpp \
	bmmessage.cpp \
	bmnetwork.cpp \
	bmnetworktcp.cpp \
	bmnetworktcpclient.cpp \
	bmnetworktcpserver.cpp \
	bytebuffer.cpp \
	byteorder.cpp \
            joinparty.cpp \
            createpartymultigamer.cpp \
    frmconnexion.cpp \
    currentProfile.cpp \
    testunitaire.cpp

HEADERS += mainwindow.h \
	windowstatistics.h \
    paramwindows.h \
    launchsologame.h \
    widgetchat.h \
    help.h \
    elttempbrick.h \
    eltplayer.h \
    eltfixedbrick.h \
    eltbrick.h \
    eltbomb.h \
    eltdecor.h \
    eltbackground.h \
    eltmobil.h \
    eltbase.h \
    eltfactory.h \
	bmerror.h \
	bmerrormanager.h \
	bmmessage.h \
	bmnetwork.h \
	bmnetworktcp.h \
	bmnetworktcpclient.h \
	bmnetworktcpserver.h \
	bytebuffer.h \
	byteorder.h\
            joinparty.h \
            createpartymultigamer.h \
    frmconnexion.h \
    currentProfile.h \
    testunitaire.h

FORMS    += mainwindow.ui \
    windowstatistics.ui \
    paramwindows.ui \
    launchsologame.ui \
    widgetchat.ui \
	joinparty.ui \
        createpartymultigamer.ui \
    frmconnexion.ui

RESOURCES += \
    Bomberman.qrc

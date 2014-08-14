#-------------------------------------------------
#
# Project created by QtCreator 2014-08-14T20:23:29
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = videoplayer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

symbian:LIBS+=-lmpxcommon
symbian:LIBS+=-lmpxplaybackutility
symbian:LIBS+=-lmpxcollectionutility
symbian:LIBS+=-lefsrv

MMP_RULES-="DEBUGGABLE_UDEBONLY"
MMP_RULES+="DEBUGGABLE"

SOURCES += main.cpp \
    playercontroller/aiplayerpluginengine.cpp \
    playercallback.cpp

HEADERS += \
    playercontroller/mpxplaybackutility.h \
    playercontroller/aiplayerpluginengineobserver.h \
    playercontroller/aiplayerpluginengine.h \
    playercallback.h

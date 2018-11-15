#-------------------------------------------------
#
# Project created by QtCreator 2018-10-25T13:53:25
#
#-------------------------------------------------

QT       += core gui sql
CONFIG		+= qt debug
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nienazwany2
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
  #defines
  win32:DEFINES += WIN32

  #includes
  INCLUDEPATH   += "$$(HALCONROOT)/include"
  INCLUDEPATH   += "$$(HALCONROOT)/include/halconcpp"

  #libs
  QMAKE_LIBDIR  += "$$(HALCONROOT)/lib/$$(HALCONARCH)"
  unix:LIBS     += -lhalconcpp -lhalcon -lXext -lX11 -ldl -lpthread
  win32:LIBS    += "$$(HALCONROOT)/lib/$$(HALCONARCH)/halconcpp.lib" \
                   "$$(HALCONROOT)/lib/$$(HALCONARCH)/halcon.lib"


CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qhalconwindow.cpp \
    obraz.cpp \
    oae.cpp \
    newdialog.cpp \
    globals.cpp \
    modifyusersdialog.cpp

HEADERS += \
        mainwindow.h \
    qhalconwindow.h \
    obraz.h \
    newdialog.h \
    globals.h \
    modifyusersdialog.h

FORMS += \
        mainwindow.ui \
    obraz.ui \
    newdialog.ui \
    modifyusersdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

# -------------------------------------------------
# Project created by QtCreator 2016-01-14T11:26:02
# -------------------------------------------------
QT += network
#
#
#
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#
#
#
TARGET = powerhmi
TEMPLATE = app
SOURCES += main.cpp \
    widgetmain.cpp \
    measure.cpp \
    constant.cpp \
    control.cpp \
    fault.cpp \
    audioplay.cpp \
    centralctl.cpp \
    tinyxml2.cpp \
    realtimefault.cpp \
    poweruserlogin.cpp \
    powerusrmanager.cpp \
    powerusraccountaddmodify.cpp \
    powerusrmodifypasswd.cpp \
    modbustcp_base.cpp \
    modbustcpserver.cpp \
    SerialCommu.cpp \
    SerialCommuBase.cpp \
    SerialCommuModbus.cpp \
    SerialCommu8330.cpp

HEADERS += widgetmain.h \
    DefineDb.h \
    measure.h \
    constant.h \
    control.h \
    fault.h \
    audioplay.h \
    centralctl.h \
    tinyxml2.h \
    realtimefault.h \
    poweruserlogin.h \
    powerusrmanager.h \
    powerusraccountaddmodify.h \
    powerusrmodifypasswd.h \
    modbustcp_base.h \
    modbustcpserver.h \
    SerialCommu.h \
    SerialCommuBase.h \
    SerialCommuModbus.h \
    modbustcpheader.h \
    SerialCommu8330.h

FORMS += widgetmain.ui \
    measure.ui \
    constant.ui \
    control.ui \
    fault.ui \
    centralctl.ui \
    realtimefault.ui \
    poweruserlogin.ui \
    powerusrmanager.ui \
    powerusraccountaddmodify.ui \
    powerusrmodifypasswd.ui

RESOURCES += \
    src.qrc



QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

#Include folders that can be found during compilation
INCLUDEPATH += /usr/local/include
include(xf/xf-core/xf-core.pri)
include(xf/xf-port-default-qt/xf-port-default-qt.pri)
include(xf/xf-port-idf/xf-port-idf.pri)

#Connects the wiringPi libraries during program execution
LIBS += -L/usr/local/lib -lwiringPi

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Controller/countdown.cpp \
    Events/evanim1.cpp \
    Events/evcntdown.cpp \
    Events/evdone.cpp \
    Events/evminus.cpp \
    Events/evplus.cpp \
    Events/evrestart.cpp \
    Model/watchpointer.cpp \
    Model/processor.cpp \
        main.cpp \
    View/observer.cpp \
    View/view.cpp \
    factory.cpp \
    Model/clock.cpp \
    Model/data.cpp \
    Controller/controller.cpp \
    Events/evrstpos.cpp

HEADERS += \
    Controller/countdown.h \
    Events/evanim1.h \
    Events/evcntdown.h \
    Events/evdone.h \
    Events/eventids.h \
    Events/evminus.h \
    Events/evplus.h \
    Events/evrestart.h \
    Model/watchpointer.h \
    Model/processor.h \
    View/observer.h \
    View/view.h \
    config/xf-config.h \
    config/xf-port-config.h \
    factory.h \
    Model/clock.h \
    Model/data.h \
    Controller/controller.h \
    Events/evrstpos.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

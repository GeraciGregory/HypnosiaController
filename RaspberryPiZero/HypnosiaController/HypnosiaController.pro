QT += core
QT += gui
QT += bluetooth

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
    factory.cpp \
    main.cpp \
    Controller/controller.cpp \
    Events/evanim1.cpp \
    Events/evanim2.cpp \
    Events/evanim3.cpp \
    Events/evanim4.cpp \
    Events/evbluetoothconnected.cpp \
    Events/evcntdown.cpp \
    Events/evdone.cpp \
    Events/evgotozero.cpp \
    Events/evminus.cpp \
    Events/evplus.cpp \
    Events/evrestart.cpp \
    Events/evrstpos.cpp \
    Model/clock.cpp \
    Model/data.cpp \
    Model/processor.cpp \
    Model/watchpointer.cpp \
    View/bluetoothinterface.cpp \
    View/observer.cpp \
    View/view.cpp \
    Library/letterlibrary.cpp \
    Library/numberlibrary.cpp \
    Controller/animation1.cpp \
    Controller/animation2.cpp \
    Controller/animation3.cpp \
    Controller/animation4.cpp \
    Events/evcalibration.cpp

HEADERS += \
    factory.h \
    config/xf-config.h \
    config/xf-port-config.h \
    Controller/controller.h \
    Events/evanim1.h \
    Events/evanim2.h \
    Events/evanim3.h \
    Events/evanim4.h \
    Events/evbluetoothconnected.h \
    Events/evcntdown.h \
    Events/evdone.h \
    Events/eventids.h \
    Events/evgotozero.h \
    Events/evminus.h \
    Events/evplus.h \
    Events/evrestart.h \
    Events/evrstpos.h \
    Model/clock.h \
    Model/data.h \
    Model/processor.h \
    Model/watchpointer.h \
    View/bluetoothinterface.h \
    View/observer.h \
    View/view.h \
    Library/letterlibrary.h \
    Library/numberlibrary.h \
    Controller/animation1.h \
    Controller/animation2.h \
    Controller/animation3.h \
    Controller/animation4.h \
    Events/evcalibration.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

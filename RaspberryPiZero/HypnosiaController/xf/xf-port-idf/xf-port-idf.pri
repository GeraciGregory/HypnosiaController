
INCLUDEPATH += $$PWD/..

SOURCES += \
    $${DEFAULT_IMPL_SOURCES}$$ \
    $$PWD/xf.cpp \
    $$PWD/port-functions.cpp \
    $$PWD/resourcefactory.cpp \
    $$PWD/eventqueue.cpp \
    $$PWD/dispatcher-active.cpp \
    $$PWD/timeoutmanager-default.cpp

HEADERS += \
    $${DEFAULT_IMPL_HEADERS}$$ \
    $$PWD/port-functions.h \
    $$PWD/resourcefactory.h \
    $$PWD/eventqueue.h \
    $$PWD/dispatcher-active.h \
    $$PWD/timeoutmanager-default.h

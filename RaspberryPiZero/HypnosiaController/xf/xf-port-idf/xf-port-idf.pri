
ABS_PATH = $$PWD   #used on windows
#ABS_PATH = $$system(pwd)   #used on linux

INCLUDEPATH += .
#INCLUDEPATH += $$PWD/..

SOURCES += \
    #$${DEFAULT_IMPL_SOURCES}$$ \
    $${ABS_PATH}/xf.cpp \
    $${ABS_PATH}/port-functions.cpp \
    $${ABS_PATH}/resourcefactory.cpp \
    $${ABS_PATH}/eventqueue.cpp \
    $${ABS_PATH}/dispatcher-active.cpp \
    $${ABS_PATH}/timeoutmanager-default.cpp

HEADERS += \
    #$${DEFAULT_IMPL_HEADERS}$$ \
    $${ABS_PATH}/port-functions.h \
    $${ABS_PATH}/resourcefactory.h \
    $${ABS_PATH}/eventqueue.h \
    $${ABS_PATH}/dispatcher-active.h \
    $${ABS_PATH}/timeoutmanager-default.h


# Absolute path to XF src files
ABS_PATH = $$PWD   #used on windows
#ABS_PATH = $$system(pwd)   #used on linux

INCLUDEPATH += .

SOURCES += \
    $${ABS_PATH}/customevent.cpp \
    $${ABS_PATH}/initialevent.cpp \
    $${ABS_PATH}/nulltransition.cpp \
    $${ABS_PATH}/behavior.cpp \
    $${ABS_PATH}/timeout.cpp

HEADERS += \
    $${ABS_PATH}/interface/resourcefactory.h \
    $${ABS_PATH}/interface/timeoutmanager.h \
    $${ABS_PATH}/interface/reactive.h \
    $${ABS_PATH}/interface/dispatcher.h \
    $${ABS_PATH}/interface/eventqueue.h \
    $${ABS_PATH}/interface/thread.h \
    $${ABS_PATH}/interface/mutex.h \
    $${ABS_PATH}/customevent.h \
    $${ABS_PATH}/event.h \
    $${ABS_PATH}/eventstatus.h \
    $${ABS_PATH}/initialevent.h \
    $${ABS_PATH}/nulltransition.h \
    $${ABS_PATH}/behavior.h \
    $${ABS_PATH}/timeout.h \
    $${ABS_PATH}/xf.h

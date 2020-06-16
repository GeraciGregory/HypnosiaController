
ABS_PATH = $$PWD   #used on windows
#ABS_PATH = $$system(pwd)   #used on linux

INCLUDEPATH += .
#INCLUDEPATH += $$PWD/..


HEADERS += \
    $${ABS_PATH}/mutex-default.h \
    $${ABS_PATH}/thread-default.h

SOURCES += \
    $${ABS_PATH}/mutex-default.cpp \
    $${ABS_PATH}/thread-default.cpp

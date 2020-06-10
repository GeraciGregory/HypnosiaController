#ifndef XF_CONFIG_H
#define XF_CONFIG_H

#include "config/xf-port-config.h"

#if (PORT_IDF_QT != 0)
    #define USE_XF_DEFAULT_IMPLEMENTATION                       0
    #define USE_XF_RESOURCE_FACTORY_DEFAULT_IMPLEMENTATION      0
    #define USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION        1
    #define USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION            0
    #define USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION     1
    #define USE_XF_MUTEX_DEFAULT_QT_IMPLEMENTATION              1
    #define USE_XF_THREAD_DEFAULT_QT_IMPLEMENTATION             1

    #define USE_XF_PORT_IDF_QT_XF_IMPLEMENTATION                1
    #define USE_XF_PORT_IDF_QT_RESOURCE_FACTORY_IMPLEMENTATION  1
    #define USE_XF_PORT_IDF_QT_EVENT_QUEUE_IMPLEMENTATION       1
    #define USE_XF_PORT_IDF_QT_PORT_FUNCTIONS_IMPLEMENTATION    1

    #include "xf-port-idf/eventqueue.h"
#endif // PORT_IDF_QT

#if (PORT_IDF_STM32CUBE != 0)
    #define USE_XF_DEFAULT_IMPLEMENTATION                                   1
    #define USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION                        1
    #define USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION                    1
    #define USE_XF_RESOURCE_FACTORY_DEFAULT_IMPLEMENTATION                  1
    #define USE_XF_MUTEX_DEFAULT_IDF_IMPLEMENTATION                         1
    #define USE_XF_EVENT_QUEUE_DEFAULT_IDF_IMPLEMENTATION                   1
    #define USE_XF_PORT_IDF_STM32CUBE_PORT_FUNCTIONS_IMPLEMENTATION         1

    #include "default-idf/eventqueue-default.h"
#ifdef __cplusplus
    using XFEventQueue = XFEventQueueDefault;
#endif // __cplusplus
#endif // PORT_IDF_STM32CUBE

#if (PORT_STM32CUBE_CMSIS_FREERTOS != 0)
    #define USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION                          1
    #define USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION                             1
    #define USE_XF_THREAD_DEFAULT_CMSIS_OS_IMPLEMENTATION                            1
    #define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_RESOURCE_FACTORY_IMPLEMENTATION     1
    #define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_TIMEOUTMANAGER_IMPLEMENTATION       1
    #define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION          1

    #include "stm32cube-cmsis-freertos/eventqueue.h"
#endif // PORT_STM32CUBE_CMSIS_FREERTOS

#if (PORT_ACTIVE_QT != 0)
    // Take all the port classes from the IDF_QT port expect...
    #define USE_XF_PORT_IDF_QT_XF_IMPLEMENTATION                    1
    #define USE_XF_PORT_IDF_QT_EVENT_QUEUE_IMPLEMENTATION           1
    #define USE_XF_PORT_IDF_QT_PORT_FUNCTIONS_IMPLEMENTATION        1

    // ... the resource factory. Must provide active dispatchers!
    #define USE_XF_PORT_ACTIVE_QT_RESOURCE_FACTORY_IMPLEMENTATION   1

    // ... mutexes and threads from the 'default-qt' port package
    #define USE_XF_MUTEX_DEFAULT_QT_IMPLEMENTATION                  1
    #define USE_XF_THREAD_DEFAULT_QT_IMPLEMENTATION                 1

    // ... and the remaining classes from the default port package.
    #define USE_XF_DEFAULT_IMPLEMENTATION                           0
    #define USE_XF_RESOURCE_FACTORY_DEFAULT_IMPLEMENTATION          0
    #define USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION            1
    #define USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION                0
    #define USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION         1

    #include "idf-qt/eventqueue.h"
#endif // PORT_ACTIVE_QT

#endif // XF_CONFIG_H

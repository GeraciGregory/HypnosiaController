#include <config/xf-config.h>

#if (USE_XF_PORT_IDF_QT_RESOURCE_FACTORY_IMPLEMENTATION != 0)

#include <QtGlobal>
#include "xf/xf-port-default-qt/thread-default.h"
#include "dispatcher-active.h"
#include "xf/xf-core/interface/mutex.h"
#include "xf/xf-core/interface/resourcefactory.h"
#include "resourcefactory.h"

using interface::XFMutex;

//static
interface::XFResourceFactory * interface::XFResourceFactory::getInstance()
{
    return XFResourceFactoryPort::getInstance();
}

// static
interface::XFResourceFactory * XFResourceFactoryPort::getInstance()
{
    static XFResourceFactoryPort theResourceFactory;
    return &theResourceFactory;
}

interface::XFDispatcher * XFResourceFactoryPort::getDefaultDispatcher()
{
    static XFDispatcherActiveDefault mainDispatcher;
    return &mainDispatcher;
}

interface::XFDispatcher * XFResourceFactoryPort::createDispatcher()
{
    // With an IDF implementation only one dispatcher is allowed. This
    // prohibits to create new dispatchers. Return the default dispatcher.
    return getDefaultDispatcher();
}

interface::XFThread * XFResourceFactoryPort::createThread(interface::XFThreadEntryPointProvider * pProvider,
                                                          interface::XFThread::EntryMethodBody entryMethod,
                                                          const char * threadName,
                                                          const uint32_t stackSize /* = 0 */)
{
    return new XFThreadDefault(pProvider, entryMethod, threadName, stackSize);
}

interface::XFMutex * XFResourceFactoryPort::createMutex()
{
    return XFMutex::create();
}

#endif // USE_XF_PORT_IDF_QT_RESOURCE_FACTORY_IMPLEMENTATION

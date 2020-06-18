#ifndef EVPLUS_H
#define EVPLUS_H

#include "xf/xf-core/customevent.h"
#include "eventids.h"

class evPlus : public XFCustomEvent
{
public:
    evPlus();
    virtual ~evPlus();
};

#endif // EVPLUS_H

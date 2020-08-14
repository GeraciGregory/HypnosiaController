#ifndef EVGOTOZERO_H
#define EVGOTOZERO_H

#include "xf/xf-core/customevent.h"
#include "eventids.h"

class evGoToZero : public XFCustomEvent
{
public:
    evGoToZero();
    virtual ~evGoToZero();
};

#endif // EVGOTOZERO_H

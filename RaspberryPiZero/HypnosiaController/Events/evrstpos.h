#ifndef EVRSTPOS_H
#define EVRSTPOS_H

#include "xf/xf-core/customevent.h"
#include "eventids.h"

class evRstPos : public XFCustomEvent
{
public:
    evRstPos();
    virtual ~evRstPos();
};

#endif // EVRSTPOS_H

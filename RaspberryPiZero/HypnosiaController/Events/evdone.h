#ifndef EVDONE_H
#define EVDONE_H

#include "xf-core/customevent.h"
#include "eventids.h"

class evDone : public XFCustomEvent
{
public:
    evDone();
    virtual ~evDone();
};

#endif // EVDONE_H

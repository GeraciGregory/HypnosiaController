#ifndef EVCNTDOWN_H
#define EVCNTDOWN_H

#include "xf/xf-core/customevent.h"
#include "eventids.h"

class evCntDown : public XFCustomEvent
{
public:
    evCntDown();
    virtual ~evCntDown();
};

#endif // EVCNTDOWN_H

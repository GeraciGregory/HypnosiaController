#ifndef EVCALIBRATION_H
#define EVCALIBRATION_H

#include "xf/xf-core/customevent.h"
#include "eventids.h"

class evCalibration : public XFCustomEvent
{
public:
    evCalibration();
    virtual ~evCalibration();
};

#endif // EVCALIBRATION_H

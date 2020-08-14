#ifndef EVBLUETOOTHCONNECTED_H
#define EVBLUETOOTHCONNECTED_H

#include "xf/xf-core/customevent.h"
#include "eventids.h"

class evBluetoothConnected : public XFCustomEvent
{
public:
    evBluetoothConnected();
    virtual ~evBluetoothConnected();
};

#endif // EVBLUETOOTHCONNECTED_H

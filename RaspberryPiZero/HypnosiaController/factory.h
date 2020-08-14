#ifndef FACTORY_H
#define FACTORY_H

#include "Controller/controller.h"
#include "Model/data.h"
#include "View/view.h"
#include "View/bluetoothinterface.h"

class Factory
{
public:
    Factory();
    ~Factory();
    void buildSystem();

private:
    //Private objects
    Data* data;
    View* view;
    BluetoothInterface* bluetooth;

protected:
    static Controller* controller;
};

#endif // FACTORY_H

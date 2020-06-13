#ifndef FACTORY_H
#define FACTORY_H

#include "Controller/controller.h"
#include "Model/data.h"
#include "View/view.h"

class Factory
{
public:
    Factory();
    ~Factory();
    void buildSystem();

private:
    Data* data;
    View* view;

protected:
    static Controller* controller;
};

#endif // FACTORY_H

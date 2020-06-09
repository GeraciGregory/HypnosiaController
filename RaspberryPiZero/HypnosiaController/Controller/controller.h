#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/data.h"

class Controller
{
public:
    Controller();
    ~Controller();
    void initializeRelation(Data* data);

private:
    Data* pData;
};

#endif // CONTROLLER_H

#ifndef DATA_H
#define DATA_H

#include "View/observer.h"
#include "clock.h"

class Data
{
public:
    Data();
    ~Data();
    void initializeRelation(Observer* observer);

private:
    Observer* pObserver;
};

#endif // DATA_H

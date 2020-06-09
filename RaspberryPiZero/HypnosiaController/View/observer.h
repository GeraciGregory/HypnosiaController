#ifndef OBSERVER_H
#define OBSERVER_H


class Observer
{
public:
    Observer();
    virtual void changed() = 0;
    virtual void stop() = 0;
};

#endif // OBSERVER_H

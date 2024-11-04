#ifndef RESOURCE_H
#define RESOURCE_H

#include "Utility.h"

class Utility;

class Resource {

protected:
        int available;
    int capacity;
    Utility* citySectors;

public:
    Resource() = default;
    Resource(int capacity) : available(capacity), capacity(capacity), citySectors(nullptr) {}
    void setMediator(Utility* m);
    virtual bool consume(int amount);
    virtual void replenish(int amount);
    virtual bool giveResource(float units) = 0;  // Pure virtual function for derived classes to implement
    virtual void receiveResource() = 0;
    virtual float getAvailableAmount() = 0;
    void setUtility(Utility* citySectors);
    //virtual void outOfResources() = 0;
    virtual ~Resource() = default;   // Virtual destructor for safe polymorphic behavior
};

#endif // RESOURCE_H

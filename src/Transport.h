#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include "Stops.h"
#include <sstream>

#include "RouteNode.h"
#include "MapIterator.h"
/**
 * @file Transport.h
 * 
 * @brief This file declares the Transport class interface
 */
class Transport
{
protected:
    RouteMap* _routes;
    int _capacity;
public:
    TravelManager* _unnamed_TravelManager_;
    Citizen* _unnamed_Citizen_;
    RouteMap* _unnamed_RouteMap_;

    virtual void setCapacity(int capacity) = 0;

    virtual void setNumPassenger(int pass) = 0;

    virtual void setCargoWeight(float weight) = 0;

    virtual float travel(Stops* stop, RouteNode* head, bool best = 0) = 0;

    virtual std::string getType() = 0;

    virtual float getWeight() = 0;

    virtual int getPassengers() = 0;

    virtual ~Transport() = default;
};

#endif


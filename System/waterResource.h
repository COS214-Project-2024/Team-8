#ifndef WATERRESOURCE_H
#define WATERRESOURCE_H

#include "Resource.h"

class waterResource : public Resource {

float availableWater;

public:
    waterResource();
    bool giveResource(float units) override;
    void receiveResource() override;
    float getAvailableAmount() override;
    //void outOfResources() override;
    ~waterResource() override = default;
};

#endif // WATERRESOURCE_H

#ifndef REVENUERESOURCE_H
#define REVENUERESOURCE_H

#include "Resource.h"

class revenueResource : public Resource {

private:
    int availableRevenue;

public:
    revenueResource();
    bool giveResource(float units) override;
    void receiveResource() override;
    float getAvailableAmount() override;
    //void outOfResources() override;
    ~revenueResource() override = default;
};

#endif // REVENUERESOURCE_H

#ifndef WASTEMANAGEMENTRESOURCE_H
#define WASTEMANAGEMENTRESOURCE_H

#include "Resource.h"

class wasteManagementResource : public Resource {

private:
    float availableWasteManagment;

public:
    wasteManagementResource();
    bool giveResource(float units) override;
    void receiveResource() override;
    float getAvailableAmount() override;    
    //void outOfResources() override;
    ~wasteManagementResource() override = default;
};

#endif // WASTEMANAGEMENTRESOURCE_H

#ifndef SEWAGEMANAGEMENTRESOURCE_H
#define SEWAGEMANAGEMENTRESOURCE_H

#include "Resource.h"

class sewageManagementResource : public Resource {

private:
    float availabeSewageMan;
public:
    sewageManagementResource();
    bool giveResource(float units) override;
    void receiveResource() override;
    float getAvailableAmount() override;    
    //void outOfResources() override;
    ~sewageManagementResource() override = default;
};

#endif // SEWAGEMANAGEMENTRESOURCE_H

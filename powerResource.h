#ifndef POWERRESOURCE_H
#define POWERRESOURCE_H

#include "Resource.h"

class powerResource : public Resource {

    private:
        int availablePower;

    public:
        powerResource();
        bool giveResource(float units) override;
        void receiveResource() override;
        float getAvailableAmount() override;
        //void outOfResources() override;
        ~powerResource() override = default;
};

#endif // POWERRESOURCE_H

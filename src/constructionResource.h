#ifndef CONSTRUCTIONRESOURCE_H
#define CONSTRUCTIONRESOURCE_H

#include "Resource.h"

class constructionResource : public Resource {

private:
    int constructionMaterial;

public:
    constructionResource();
    bool giveResource(float units) override;
    void receiveResource() override;
    float getAvailableAmount() override;
    //void outOfResources() override;
    ~constructionResource() override = default;
};

#endif // POWERRESOURCE_H

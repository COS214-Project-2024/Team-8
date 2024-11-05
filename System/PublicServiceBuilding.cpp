#include "PublicServiceBuilding.h"

PublicServiceBuilding::PublicServiceBuilding() : Buildings(), waste(0) {
}

PublicServiceBuilding::~PublicServiceBuilding() {
    // Base class destructor will handle cleanup
}

int PublicServiceBuilding::getWasteCost() {
    return waste;
}
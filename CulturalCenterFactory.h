#ifndef CULTURALCENTERFACTORY_H
#define CULTURALCENTERFACTORY_H

#include "Buildings.h"
#include "LandmarkFactory.h"

/**
 * @class CulturalCenterFactory
 * @brief Factory class for creating instances of CulturalCenter buildings.
 */
class CulturalCenterFactory : LandmarkFactory {

public:
    Buildings* buildings; /**< Pointer to a Buildings instance used by the factory. */

    /**
     * @brief Creates a new CulturalCenter building.
     * @return Pointer to the created Buildings object.
     */
    virtual Buildings* createBuilding();
};

#endif

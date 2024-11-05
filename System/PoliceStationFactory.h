#ifndef POLICESTATIONFACTORY_H
#define POLICESTATIONFACTORY_H

#include "Buildings.h"
#include "PublicServiceFactory.h"

/**
 * @class PoliceStationFactory
 * @brief Factory class for creating instances of PoliceStation.
 */
class PoliceStationFactory : public PublicServiceFactory {

public:
    Buildings* buildings; ///< Pointer to a Building instance

    /**
     * @brief Creates an instance of a PoliceStation.
     * @return Pointer to the created PoliceStation building.
     */
    virtual Buildings* createBuilding();
};

#endif

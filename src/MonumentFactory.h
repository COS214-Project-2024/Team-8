#ifndef MONUMENTFACTORY_H
#define MONUMENTFACTORY_H

#include "Buildings.h"
#include "LandmarkFactory.h"

/**
 * @class MonumentFactory
 * @brief Abstract factory class for creating Monument objects.
 */
class MonumentFactory : LandmarkFactory {

public:
    Buildings* buildings; /**< Pointer to a Buildings object. */

    /**
     * @brief Pure virtual function to create a building.
     * @return Pointer to a Buildings object.
     */
    virtual Buildings* createBuilding() = 0;
};

#endif

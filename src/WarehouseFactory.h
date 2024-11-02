#ifndef WAREHOUSEFACTORY_H
#define WAREHOUSEFACTORY_H

#include "Buildings.h"
#include "IndustrialFactory.h"

/**
 * @class WarehouseFactory
 * @brief Factory class for creating Warehouse buildings.
 */
class WarehouseFactory : public IndustrialFactory {

public:
    Buildings* buildings; ///< Pointer to the created warehouse building.

    /**
     * @brief Creates a new Warehouse building.
     * @return A pointer to the newly created Warehouse object.
     */
    virtual Buildings* createBuilding();
};

#endif

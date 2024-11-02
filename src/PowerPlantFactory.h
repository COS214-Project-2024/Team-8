/**
 * @file PowerPlantFactory.h
 * @brief Defines the PowerPlantFactory class interface.
 */

#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "Buildings.h"
#include "IndustrialFactory.h"

/**
 * @class PowerPlantFactory
 * @brief A factory class for creating power plant buildings.
 *
 * This class inherits from IndustrialFactory and provides a method
 * for creating power plant building objects.
 */
class PowerPlantFactory : IndustrialFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the power plant building instance managed by the factory. */

	/**
	 * @brief Creates a new power plant building.
	 *
	 * This function creates and returns a pointer to a new power plant Buildings object.
	 *
	 * @return A pointer to a newly created power plant Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

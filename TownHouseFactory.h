/**
 * @file TownhouseFactory.h
 * @brief Defines the TownhouseFactory class interface.
 */

#ifndef TOWNHOUSEFACTORY_H
#define TOWNHOUSEFACTORY_H

#include "ResidentialFactory.h"
#include "Buildings.h"

/**
 * @class TownhouseFactory
 * @brief A factory class for creating townhouse buildings.
 *
 * This class inherits from ResidentialFactory and provides a method
 * for creating townhouse building objects.
 */
class TownHouseFactory : public ResidentialFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the townhouse building instance managed by the factory. */

	/**
	 * @brief Creates a new townhouse building.
	 *
	 * This function creates and returns a pointer to a new townhouse Buildings object.
	 *
	 * @return A pointer to a newly created townhouse Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif


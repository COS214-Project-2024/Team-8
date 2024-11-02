/**
 * @file HouseFactory.h
 * @brief Defines the HouseFactory class interface.
 */

#ifndef HOUSEFACTORY_H
#define HOUSEFACTORY_H

#include "Buildings.h"
#include "ResidentialFactory.h"

/**
 * @class HouseFactory
 * @brief A factory class for creating house buildings.
 *
 * This class inherits from ResidentialFactory and provides a method
 * for creating house building objects.
 */
class HouseFactory : ResidentialFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the house building instance managed by the factory. */

	/**
	 * @brief Creates a new house building.
	 *
	 * This function creates and returns a pointer to a new house Buildings object.
	 *
	 * @return A pointer to a newly created house Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

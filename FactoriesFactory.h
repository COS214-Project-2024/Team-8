/**
 * @file FactoriesFactory.h
 * @brief Defines the FactoriesFactory class interface.
 */

#ifndef FACTORIESFACTORY_H
#define FACTORIESFACTORY_H

#include "Buildings.h"
#include "IndustrialFactory.h"

/**
 * @class FactoriesFactory
 * @brief A factory class for creating factory buildings.
 *
 * This class inherits from IndustrialFactory and provides a method
 * for creating factory building objects.
 */
class FactoriesFactory : public IndustrialFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the factory building instance managed by the factory. */

	/**
	 * @brief Creates a new factory building.
	 *
	 * This function creates and returns a pointer to a new factory Buildings object.
	 *
	 * @return A pointer to a newly created factory Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

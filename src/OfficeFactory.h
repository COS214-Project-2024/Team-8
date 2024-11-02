/**
 * @file OfficeFactory.h
 * @brief Defines the OfficeFactory class interface.
 */

#ifndef OFFICEFACTORY_H
#define OFFICEFACTORY_H

#include "Buildings.h"
#include "CommercialFactory.h"

/**
 * @class OfficeFactory
 * @brief A factory class for creating office buildings.
 *
 * This class inherits from CommercialFactory and provides a method
 * for creating office building objects.
 */
class OfficeFactory : CommercialFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the office building instance managed by the factory. */

	/**
	 * @brief Creates a new office building.
	 *
	 * This function creates and returns a pointer to a new office Buildings object.
	 *
	 * @return A pointer to a newly created office Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

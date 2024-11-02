/**
 * @file ParkFactory.h
 * @brief Defines the ParkFactory class interface.
 */

#ifndef PARKFACTORY_H
#define PARKFACTORY_H

#include "Buildings.h"
#include "LandmarkFactory.h"

/**
 * @class ParkFactory
 * @brief A factory class for creating park buildings.
 *
 * This class inherits from LandmarkFactory and provides a method
 * for creating park building objects.
 */
class ParkFactory : LandmarkFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the park building instance managed by the factory. */

	/**
	 * @brief Creates a new park building.
	 *
	 * This function creates and returns a pointer to a new park Buildings object.
	 *
	 * @return A pointer to a newly created park Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

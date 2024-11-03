/**
 * @file ApartmentFactory.h
 * @brief Defines the ApartmentFactory class interface.
 */

#ifndef APARTMENTFACTORY_H
#define APARTMENTFACTORY_H

#include "Buildings.h"
#include "ResidentialFactory.h"

/**
 * @class ApartmentFactory
 * @brief A factory class for creating apartment buildings.
 *
 * This class inherits from ResidentialFactory and provides a method
 * for creating apartment building objects.
 */
class ApartmentFactory : public ResidentialFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the apartment building instance managed by the factory. */

	/**
	 * @brief Creates a new apartment building.
	 *
	 * This function creates and returns a pointer to a new apartment Buildings object.
	 *
	 * @return A pointer to a newly created apartment Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

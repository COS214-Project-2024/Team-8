#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingFactory.h"

/**
 * @class ResidentialFactory
 * @brief A factory class for creating residential buildings.
 *
 * This class inherits from BuildingFactory and provides an interface for
 * creating residential building objects. Derived classes must implement
 * the createBuilding() method to produce specific types of residential buildings.
 */
class ResidentialFactory : public BuildingFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the residential building instance managed by the factory. */

	/**
	 * @brief Creates a new residential building.
	 *
	 * Pure virtual function that must be implemented by derived classes to
	 * create and return a pointer to a new residential Buildings object.
	 *
	 * @return A pointer to a newly created residential Buildings object.
	 */
	virtual Buildings* createBuilding() = 0;
	virtual ~ResidentialFactory(){}
};

#endif

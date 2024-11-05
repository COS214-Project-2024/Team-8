/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class interface.
 */

#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Buildings.h"

/**
 * @class BuildingFactory
 * @brief An abstract factory class for creating Building objects.
 *
 * This class defines a factory interface for creating building objects.
 * Derived classes must implement the createBuilding() method to produce
 * specific types of buildings.
 */
class BuildingFactory {

private:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the building instance managed by the factory. */

public:
	/**
	 * @brief Creates a new building.
	 *
	 * Pure virtual function that must be implemented by derived classes to
	 * create and return a pointer to a new Buildings object.
	 *
	 * @return A pointer to a newly created Buildings object.
	 */
	virtual Buildings* createBuilding() = 0;
};

#endif

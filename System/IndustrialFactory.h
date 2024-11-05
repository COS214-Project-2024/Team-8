/**
 * @file IndustrialFactory.h
 * @brief Defines the IndustrialFactory class interface.
 */

#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include "BuildingFactory.h"

/**
 * @class IndustrialFactory
 * @brief A factory class for creating industrial buildings.
 *
 * This class inherits from BuildingFactory and provides an interface for
 * creating industrial building objects. Derived classes must implement
 * the createBuilding() method to produce specific types of industrial buildings.
 */
class IndustrialFactory : public BuildingFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the industrial building instance managed by the factory. */

	/**
	 * @brief Creates a new industrial building.
	 *
	 * Pure virtual function that must be implemented by derived classes to
	 * create and return a pointer to a new industrial Buildings object.
	 *
	 * @return A pointer to a newly created industrial Buildings object.
	 */
	virtual Buildings* createBuilding() = 0;
};

#endif

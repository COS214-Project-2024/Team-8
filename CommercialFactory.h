/**
 * @file CommercialFactory.h
 * @brief Defines the CommercialFactory class interface.
 */

#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "Buildings.h"
#include "BuildingFactory.h"

/**
 * @class CommercialFactory
 * @brief A factory class for creating commercial buildings.
 *
 * This class inherits from BuildingFactory and provides an interface for
 * creating commercial building objects. Derived classes must implement
 * the createBuilding() method to produce specific types of commercial buildings.
 */
class CommercialFactory : public BuildingFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the commercial building instance managed by the factory. */

	/**
	 * @brief Creates a new commercial building.
	 *
	 * Pure virtual function that must be implemented by derived classes to
	 * create and return a pointer to a new commercial Buildings object.
	 *
	 * @return A pointer to a newly created commercial Buildings object.
	 */
	virtual Buildings* createBuilding() = 0;
	virtual ~CommercialFactory(){}
};

#endif

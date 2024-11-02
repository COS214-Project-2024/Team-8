#ifndef PUBLICSERVICEFACTORY_H
#define PUBLICSERVICEFACTORY_H

#include "BuildingFactory.h"

/**
 * @class PublicServiceFactory
 * @brief A factory class for creating public service buildings.
 *
 * This class inherits from BuildingFactory and provides an interface for
 * creating public service building objects. Derived classes must implement
 * the createBuilding() method to produce specific types of public service buildings.
 */
class PublicServiceFactory : public BuildingFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the public service building instance managed by the factory. */

	/**
	 * @brief Creates a new public service building.
	 *
	 * Pure virtual function that must be implemented by derived classes to
	 * create and return a pointer to a new public service Buildings object.
	 *
	 * @return A pointer to a newly created public service Buildings object.
	 */
	virtual Buildings* createBuilding() = 0;
};

#endif

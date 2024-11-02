/**
 * @file SchoolFactory.h
 * @brief Defines the SchoolFactory class interface.
 */

#ifndef SCHOOLFACTORY_H
#define SCHOOLFACTORY_H

#include "Buildings.h"
#include "PublicServiceFactory.h"

/**
 * @class SchoolFactory
 * @brief A factory class for creating school buildings.
 *
 * This class inherits from PublicServiceFactory and provides a method
 * for creating school building objects.
 */
class SchoolFactory : public PublicServiceFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the school building instance managed by the factory. */

	/**
	 * @brief Creates a new school building.
	 *
	 * This function creates and returns a pointer to a new school Buildings object.
	 *
	 * @return A pointer to a newly created school Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

/**
 * @file ShopFactory.h
 * @brief Defines the ShopFactory class interface.
 */

#ifndef SHOPFACTORY_H
#define SHOPFACTORY_H

#include "Buildings.h"
#include "CommercialFactory.h"

/**
 * @class ShopFactory
 * @brief A factory class for creating shop buildings.
 *
 * This class inherits from CommercialFactory and provides a method
 * for creating shop building objects.
 */
class ShopFactory : public CommercialFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the shop building instance managed by the factory. */

	/**
	 * @brief Creates a new shop building.
	 *
	 * This function creates and returns a pointer to a new shop Buildings object.
	 *
	 * @return A pointer to a newly created shop Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

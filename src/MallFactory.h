/**
 * @file MallFactory.h
 * @brief Defines the MallFactory class interface.
 */

#ifndef MALLFACTORY_H
#define MALLFACTORY_H

#include "Buildings.h"
#include "CommercialFactory.h"

/**
 * @class MallFactory
 * @brief A factory class for creating mall buildings.
 *
 * This class inherits from CommercialFactory and provides an interface for
 * creating mall building objects. Derived classes must implement the
 * createBuilding() method to produce specific types of mall buildings.
 */
class MallFactory : CommercialFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the mall building instance managed by the factory. */

	/**
	 * @brief Creates a new mall building.
	 *
	 * Pure virtual function that must be implemented by derived classes to
	 * create and return a pointer to a new mall Buildings object.
	 *
	 * @return A pointer to a newly created mall Buildings object.
	 */
	virtual Buildings* createBuilding() = 0;
};

#endif

/**
 * @file LandmarkFactory.h
 * @brief Defines the LandmarkFactory class interface.
 */

#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"

/**
 * @class LandmarkFactory
 * @brief A factory class for creating landmark buildings.
 *
 * This class inherits from BuildingFactory and provides an interface for
 * creating landmark building objects. Derived classes must implement
 * the createBuilding() method to produce specific types of landmark buildings.
 */
class LandmarkFactory : public BuildingFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the landmark building instance managed by the factory. */

	/**
	 * @brief Creates a new landmark building.
	 *
	 * Pure virtual function that must be implemented by derived classes to
	 * create and return a pointer to a new landmark Buildings object.
	 *
	 * @return A pointer to a newly created landmark Buildings object.
	 */
	virtual Buildings* createBuilding() = 0;
};

#endif

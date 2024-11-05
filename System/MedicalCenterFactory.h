/**
 * @file MedicalCenterFactory.h
 * @brief Defines the MedicalCenterFactory class interface.
 */

#ifndef MEDICALCENTERFACTORY_H
#define MEDICALCENTERFACTORY_H

#include "Buildings.h"
#include "PublicServiceFactory.h"

/**
 * @class MedicalCenterFactory
 * @brief A factory class for creating medical center buildings.
 *
 * This class inherits from PublicServiceFactory and provides a method
 * for creating medical center building objects.
 */
class MedicalCenterFactory : public PublicServiceFactory {

public:
	Buildings* buildings; /**< Pointer to a Buildings object, representing the medical center building instance managed by the factory. */

	/**
	 * @brief Creates a new medical center building.
	 *
	 * This function creates and returns a pointer to a new medical center Buildings object.
	 *
	 * @return A pointer to a newly created medical center Buildings object.
	 */
	virtual Buildings* createBuilding();
};

#endif

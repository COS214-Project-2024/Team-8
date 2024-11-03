#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "UtilityFactory.h"
#include "UtilityPowerPlant.h"
/**
 * @file PowerPlantFactory.h
 * 
 * @brief The header file for the PowerPlantFactory class
 */
class PowerPlantFactory : public UtilityFactory {
public:
	Utility* createUtility(float output);
};

#endif

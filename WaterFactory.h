#ifndef WATERFACTORY_H
#define WATERFACTORY_H

#include "UtilityFactory.h"
#include "WaterSupply.h"
/**
 * @file WaterFactory.h
 * 
 * @brief The header file for the WaterFactory class
 */
class WaterFactory : public UtilityFactory {
public:
	Utility* createUtility(float output);
};

#endif

#ifndef SEWAGEFACTORY_H
#define SEWAGEFACTORY_H

#include "UtilityFactory.h"
#include "SewageSystems.h"
/**
 * @file SewageFactory.h
 * 
 * @brief The header file for the SewageFactory class
 */
class SewageFactory : public UtilityFactory {
public:
	Utility* createUtility(float output);
};

#endif

#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "Utility.h"
/**
 * @file UtilityFactory.h
 * 
 * @brief The header file for the UtilityFactory class
 */
class UtilityFactory {
public:
	virtual Utility* createUtility(float output) = 0;
	virtual ~UtilityFactory() {};
};

#endif

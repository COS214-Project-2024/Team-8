#ifndef WASTEFACTORY_H
#define WASTEFACTORY_H

#include "UtilityFactory.h"
#include "WasteManagement.h"
/**
 * @file WasteFactory.h
 * 
 * @brief The header file for the WasteFactory class
 */
class WasteFactory : public UtilityFactory {
public:
	Utility* createUtility(float output);
};

#endif

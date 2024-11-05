#ifndef WINDFACTORY_H
#define WINDFACTORY_H

#include "EnergyFactory.h"
#include "WindSource.h"
/**
 * @file WindFactory.h
 * 
 * @brief The header file for the WindFactory class
 */
class WindFactory : public EnergyFactory {
public:
	EnergySource* createEnergySource(float output);
};

#endif
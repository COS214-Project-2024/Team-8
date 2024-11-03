#ifndef ENERGYFACTORY_H
#define ENERGYFACTORY_H

#include "EnergySource.h"
/**
 * @file EnergyFactory.h
 * 
 * @brief The header file for the EnergyFactory class
 */
class EnergyFactory {
public:
	virtual EnergySource* createEnergySource(float output) = 0;
};

#endif

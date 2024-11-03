#ifndef NUCLEARFACTORY_H
#define NUCLEARFACTORY_H

#include "EnergyFactory.h"
#include "NuclearSource.h"
/**
 * @file NuclearFactory.h
 * 
 * @brief The header file for the NuclearFactory class
 */
class NuclearFactory : public EnergyFactory {
public:
	EnergySource* createEnergySource(float output);
};

#endif

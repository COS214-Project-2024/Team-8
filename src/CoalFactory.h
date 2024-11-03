#ifndef COALFACTORY_H
#define COALFACTORY_H

#ifndef COALFACTORY_H
#define COALFACTORY_H

#include "EnergyFactory.h"
#include "CoalSource.h"
/**
 * @file CoalFactory.h
 * 
 * @brief The header file for the CoalFactory class
 */
class CoalFactory : public EnergyFactory {
public:
	EnergySource* createEnergySource(float output);
};

#endif

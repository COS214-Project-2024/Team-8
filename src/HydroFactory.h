#ifndef HYDROFACTORY_H
#define HYDROFACTORY_H

#ifndef HYDROFACTORY_H
#define HYDROFACTORY_H

#include "EnergyFactory.h"
#include "HydroSource.h"
/**
 * @file HydroFactory.h
 * 
 * @brief The header file for the HydroFactory class
 */
class HydroFactory : public EnergyFactory {
public:
	EnergySource* createEnergySource(float output);
};

#endif

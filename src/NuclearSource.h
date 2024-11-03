#ifndef NUCLEARSOURCE_H
#define NUCLEARSOURCE_H
#ifndef NUCLEARSOURCE_H
#define NUCLEARSOURCE_H

#include "EnergySource.h"
/**
 * @file NuclearSource.h
 * 
 * @brief The header file for the NuclearSource class
 */
class NuclearSource : public EnergySource {
public:
	NuclearSource(float output);

	float getEnergyOutput();
	float getEnergyOutput();

	std::string getFuelType();
	std::string getFuelType();
};

#endif

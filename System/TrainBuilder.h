#ifndef TRAINBUILDER_H
#define TRAINBUILDER_H

#include "TransportBuilder.h"
#include "Train.h"
/**
 * @file TrainBuilder.h
 * 
 * @brief This file declares the TrainBuilder class
 */
class TrainBuilder : public TransportBuilder {
public:
	TrainBuilder();
	
	TransportBuilder* setCapacity(int capacity);

	TransportBuilder* setCargoWeight(float weight);

	TransportBuilder* setNumPassengers(int num);

	Transport* build();
};

#endif

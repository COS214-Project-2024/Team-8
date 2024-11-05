#ifndef PLANEBUILDER_H
#define PLANEBUILDER_H

#include "TransportBuilder.h"
#include "Plane.h"

/**
 * @file PlaneBuilder.h
 * 
 * @brief This file implements the PlaneBuilder class
 * 
 * The PlaneBuilder class is a subclass of the TransportBuilder class
 */
class PlaneBuilder : public TransportBuilder {
public:
	PlaneBuilder();

	TransportBuilder* setCapacity(int capacity);

	TransportBuilder* setCargoWeight(float weight);

	TransportBuilder* setNumPassengers(int num);

	Transport* build();
};

#endif

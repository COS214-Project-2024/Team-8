#ifndef PLANEBUILDER_H
#define PLANEBUILDER_H

#include "TransportBuilder.h"
#include "Plane.h"
class PlaneBuilder : public TransportBuilder {
public:
	PlaneBuilder();

	TransportBuilder* setCapacity(int capacity);

	TransportBuilder* setCargoWeight(float weight);

	TransportBuilder* setNumPassengers(int num);

	Transport* build();
};

#endif

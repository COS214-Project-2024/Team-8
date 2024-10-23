#ifndef VEHICLEBUILDER_H
#define VEHICLEBUILDER_H

#include "TransportBuilder.h"
#include "Vehicle.h"
class VehicleBuilder : public TransportBuilder {
public:
	VehicleBuilder();
	
	TransportBuilder* setCapacity(int capacity);

	TransportBuilder* setCargoWeight(float weight);

	TransportBuilder* setNumPassengers(int num);

	Transport* build();
};

#endif

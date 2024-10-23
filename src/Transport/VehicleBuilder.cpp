#include "VehicleBuilder.h"

TransportBuilder* VehicleBuilder::setCapacity(int capacity) {
	this->transport->setCapacity(capacity);
	return this;
}

TransportBuilder* VehicleBuilder::setCargoWeight(float weight) {
	this->transport->setCargoWeight(weight);
	return this;
}

TransportBuilder* VehicleBuilder::setNumPassengers(int num) {
	this->transport->setNumPassenger(num);
	return this;
}

Transport* VehicleBuilder::build() {
	return this->transport;
}

VehicleBuilder::VehicleBuilder() {
	this->transport = new Vehicle(0);
}

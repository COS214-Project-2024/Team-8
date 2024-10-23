#include "PlaneBuilder.h"

TransportBuilder* PlaneBuilder::setCapacity(int capacity) {
	this->transport->setCapacity(capacity);
	return this;
}

TransportBuilder* PlaneBuilder::setCargoWeight(float weight) {
	this->transport->setCargoWeight(weight);
	return this;
}

TransportBuilder* PlaneBuilder::setNumPassengers(int num) {
	this->transport->setNumPassenger(num);
	return this;
}

Transport* PlaneBuilder::build() {
	return this->transport;
}

PlaneBuilder::PlaneBuilder() {
	this->transport = new Plane(0);
}

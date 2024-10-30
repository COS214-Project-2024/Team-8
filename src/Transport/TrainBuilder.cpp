#include "TrainBuilder.h"

TransportBuilder* TrainBuilder::setCapacity(int capacity) {
	this->transport->setCapacity(capacity);
	return this;
}

TransportBuilder* TrainBuilder::setCargoWeight(float weight) {
	this->transport->setCargoWeight(weight);
	return this;
}

TransportBuilder* TrainBuilder::setNumPassengers(int num) {
	this->transport->setNumPassenger(num);
	return this;
}

Transport* TrainBuilder::build() {
	return this->transport;
}

TrainBuilder::TrainBuilder() {
	this->transport = new Train(0);
}

#include "VehicleBuilder.h"
/**
 * @file VehicleBuilder.cpp
 * 
 * @brief This file implements the VehicleBuilder class
 */

/**
 * @brief Used to set the capacity of the vehicle
 * @param capacity integer value of the capacity
 * @return VehicleBuilder* pointer to the VehicleBuilder object for chaining
 */
TransportBuilder* VehicleBuilder::setCapacity(int capacity) {
	this->transport->setCapacity(capacity);
	return this;
}

/**
 * @brief Used to set the weight of the cargo
 * @param weight float value of the weight
 * @return VehicleBuilder* pointer to the VehicleBuilder object for chaining
 */
TransportBuilder* VehicleBuilder::setCargoWeight(float weight) {
	this->transport->setCargoWeight(weight);
	return this;
}

/**
 * @brief Used to set the number of passengers
 * @param num integer value of the number of passengers
 * @return VehicleBuilder* pointer to the VehicleBuilder object for chaining
 */
TransportBuilder* VehicleBuilder::setNumPassengers(int num) {
	this->transport->setNumPassenger(num);
	return this;
}

/**
 * @brief Used to build the vehicle object
 * @return Transport* pointer to the vehicle object
 */
Transport* VehicleBuilder::build() {
	return this->transport;
}

/**
 * @brief Construct a new Vehicle Builder:: Vehicle Builder object
 * 
 * Creates a new Vehicle object with a capacity of 0(place holder)
 */
VehicleBuilder::VehicleBuilder() {
	this->transport = new Vehicle(0);
}

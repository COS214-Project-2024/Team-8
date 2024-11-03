#include "PlaneBuilder.h"
/**
 * @file PlaneBuilder.cpp
 * 
 * @brief This file implements the PlaneBuilder class
 */

/**
 * @brief Used to set the capacity of the plane
 * 
 * @param capacity integer value of the capacity
 * @return PlaneBuilder* pointer to the PlaneBuilder object for chaining
 */
TransportBuilder* PlaneBuilder::setCapacity(int capacity) {
	this->transport->setCapacity(capacity);
	return this;
}

/**
 * @brief Set the Cargo Weight object
 * 
 * @param weight float value of the weight
 * @return PlaneBuilder* pointer to the PlaneBuilder object for chaining
 */
TransportBuilder* PlaneBuilder::setCargoWeight(float weight) {
	this->transport->setCargoWeight(weight);
	return this;
}

/**
 * @brief Set the Num Passengers object
 * 
 * @param num integer value of the number of passengers
 * @return PlaneBuilder* pointer to the PlaneBuilder object for chaining
 */
TransportBuilder* PlaneBuilder::setNumPassengers(int num) {
	this->transport->setNumPassenger(num);
	return this;
}

/**
 * @brief Build the Plane object
 * @pre The PlaneBuilder object has been constructed
 * @return Transport* pointer to the Plane object
 */
Transport* PlaneBuilder::build() {
	return this->transport;
}

/**
 * @brief Construct a new Plane Builder:: Plane Builder object
 * 
 * Creates a new Plane object with a capacity of 0(place holder)
 */
PlaneBuilder::PlaneBuilder() {
	this->transport = new Plane(0);
}

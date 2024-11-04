#include "TrainBuilder.h"
/**
 * @file TrainBuilder.cpp
 * 
 * @brief This file implements the TrainBuilder class
 */

/**
 * @brief Used to set the capacity of the train
 * 
 * @param capacity integer value of the capacity
 * @return TrainBuilder* pointer to the TrainBuilder object for chaining
 */
TransportBuilder* TrainBuilder::setCapacity(int capacity) {
	this->transport->setCapacity(capacity);
	return this;
}

/**
 * @brief Set the Cargo Weight object
 * 
 * @param weight float value of the weight
 * @return TrainBuilder* pointer to the TrainBuilder object for chaining
 */
TransportBuilder* TrainBuilder::setCargoWeight(float weight) {
	this->transport->setCargoWeight(weight);
	return this;
}

/**
 * @brief Set the Num Passengers object
 * 
 * @param num integer value of the number of passengers
 * @return TrainBuilder* pointer to the TrainBuilder object for chaining
 */
TransportBuilder* TrainBuilder::setNumPassengers(int num) {
	this->transport->setNumPassenger(num);
	return this;
}

/**
 * @brief Build the Train object
 * 
 * @pre The transport object has been constructed
 * @return Transport* pointer to the Train object
 */
Transport* TrainBuilder::build() {
	return this->transport;
}

/**
 * @brief Construct a new Train Builder:: Train Builder object
 * 
 * Creates a new Train object with a capacity of 0(place holder)
 */
TrainBuilder::TrainBuilder() {
	this->transport = new Train(0);
}

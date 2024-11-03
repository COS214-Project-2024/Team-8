#include "TravelManager.h"

/**
 * @file TravelManager.cpp
 * 
 * @brief This file implements the TravelManager class
 * 
 * This class is responsible for managing the travel of the vehicles to destinations using routing techniques
 */
void TravelManager::Travel(int capacity, Stops* destination, float weight) {
	int passengers = rand() % capacity + 1;
	if(capacity <= 56){
		builder = new VehicleBuilder();
	}else if(capacity <= 200){
		builder = new TrainBuilder();
	}else{
		builder = new PlaneBuilder();
	}

	if(weight == 0){
		constructPassenger(capacity, passengers);
	}else{
		constructCargo(capacity, weight);
	}
	Travel(this->transport, destination);
}

/**
 * @brief Construct a new Cargo object
 * 
 * @param capacity the capacity of the vehicle
 * @param weight the weight of the cargo
 * 
 * @post The vehicle is constructed with the given capacity and weight
 */
void TravelManager::constructCargo(int capacity, float weight) {
	this->transport = builder->setCapacity(capacity)
							->setCargoWeight(weight)
							->build();
}

/**
 * @brief Construct a new Passenger object
 * 
 * @param capacity the capacity of the vehicle
 * @param passengers the number of passengers
 * 
 * @post The vehicle is constructed with the given capacity and number of passengers
 */
void TravelManager::constructPassenger(int capacity, int passengers) {
	this->transport = builder->setCapacity(capacity)
							->setNumPassengers(passengers)
							->build();
}

/**
 * @brief Add a stop to the route
 * 
 * @param stop is the stop to add
 * 
 * @post The stop is added to the route
 */
void TravelManager::addStops(Stops* stop) {
	route->add(stop);
}

/**
 * @brief Destroy the Travel Manager object
 * @pre The route is not null
 * @post The route is deleted
 * The transport is deleted if it exists
 * The builder is deleted if it exists
 */
TravelManager::~TravelManager() {
	delete this->route;
	if(transport) delete this->transport;
	if(builder) delete this->builder;
}

/**
 * @brief Construct a new Travel Manager object
 * 
 * @post The route is constructed
 * The distance travelled is set to 0
 * The transport is set to null
 */
TravelManager::TravelManager() {
	this->route = new AccesibleRoute();
	this->distanceTravelled = 0;
	this->transport = nullptr;
}

/**
 * @brief Travel to the destination using the constructed transport ny nest route
 * 
 * @param capacity the capacity of the vehicle
 * @param destination the destination to travel to
 * @param weight the weight of the cargo
 * 
 * This function is used to travel to the destination using the constructed transport using the shortest distance
 * @post The vehicle travels to the destination
 */
void TravelManager::BestRoute(int capacity, Stops* destination, float weight) {
	int passengers = rand() % capacity + 1;
	if(capacity <= 56){
		builder = new VehicleBuilder();
	}else if(capacity <= 200){
		builder = new TrainBuilder();
	}else{
		builder = new PlaneBuilder();
	}

	if(weight == 0){
		constructPassenger(capacity, passengers);
	}else{
		constructCargo(capacity, weight);
	}
	BestRoute(this->transport, destination);
}

/**
 * @brief Travel to the destination using the given transport
 * @param Transport* trans a pointer to the transport to use
 * @param Stops* destination the destination to travel to
 * 
 * This function is used to travel to the destination using the given transport
 * @post The vehicle travels to the destination
 */
void TravelManager::Travel(Transport* trans, Stops* destination) {
	this->distanceTravelled = trans->travel(destination, route);
	if(distanceTravelled == 0){
		std::cout << "No route found" << std::endl;
	}else{
		std::cout << "============Travel Summary============"<<std::endl;
		std::cout << "Transport Used: "<< trans->getType() << std::endl;
		std::cout << "Distance Travelled: "<< distanceTravelled << std::endl;
		if(trans->getWeight() == 0){
			std::cout << "Number of Passengers: "<< trans->getPassengers() << std::endl;
		}else{
			std::cout<< "Weight of Cargo: "<< trans->getWeight() << std::endl;
		}
		std::cout << "======================================"<<std::endl;
	}

}

/**
 * @brief Travel to the destination using the given transport by using the shortest distance
 * @param Transport* trans a pointer to the transport to use
 * @param Stops* destination the destination to travel to
 * 
 * This function is used to travel to the destination using the given transport using the shortest distance
 * @post The vehicle travels to the destination
 */
void TravelManager::BestRoute(Transport* trans, Stops* destination) {
	this->distanceTravelled = trans->travel(destination, route, true);
	if(distanceTravelled == 0){
		std::cout << "No route found" << std::endl;
	}else{
		std::cout << "============Travel Summary============"<<std::endl;
		std::cout << "Transport Used: "<< trans->getType() << std::endl;
		std::cout << "Distance Travelled: "<< distanceTravelled << std::endl;
		if(trans->getWeight() == 0){
			std::cout << "Number of Passengers: "<< trans->getPassengers() << std::endl;
		}else{
			std::cout<< "Weight of Cargo: "<< trans->getWeight() << std::endl;
		}
		std::cout << "======================================"<<std::endl;
	}
}

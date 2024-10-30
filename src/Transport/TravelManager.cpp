#include "TravelManager.h"

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

void TravelManager::constructCargo(int capacity, float weight) {
	this->transport = builder->setCapacity(capacity)
							->setCargoWeight(weight)
							->build();
}

void TravelManager::constructPassenger(int capacity, int passengers) {
	this->transport = builder->setCapacity(capacity)
							->setNumPassengers(passengers)
							->build();
}

void TravelManager::addStops(Stops* stop) {
	this->route->add(stop);
}

TravelManager::~TravelManager() {
	delete this->route;
	delete this->transport;
	delete this->builder;
}

TravelManager::TravelManager() {
	this->route = new AccesibleRoute();
	this->distanceTravelled = 0;
}

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

#include "Vehicle.h"

Vehicle::Vehicle(int capacity) {
	setCapacity(capacity);
	this->isCargo = false;
	this->passengers = 1;
	this->weight = 0;
}

void Vehicle::setNumPassenger(int pass) {
	this->passengers = pass;
	this->isCargo = false;
	this->weight = 0;
}

void Vehicle::setCargoWeight(float weight) {
	this->weight = weight;
	this->isCargo = true;
	this->passengers = 1;
	this->transportType = "Truck";
}

float Vehicle::travel(Stops* stop, RouteNode* head, bool best) {
	MapIterator* iter = new MapIterator(head);
	float distance = 0;
	if(best){
		//would skip symbols 'T" and 'A' in the route
		while(iter->currentNode() == nullptr && iter->operator*() != stop){
			if(iter->operator*()->getSymbol() == 'T' || iter->operator*()->getSymbol() == 'A'){
				++iter;
				continue;
			}
			distance += iter->operator*()->getDistance();
			++iter;
		}
	}else{
		while( iter->currentNode() == nullptr && iter->operator*() != stop){
			distance += iter->operator*()->getDistance();
			++iter;
		}
	}

	if(iter->currentNode() == nullptr){
		delete iter;
		return 0;
	}
	else{
		delete iter;
		return distance;
	}
}

float Vehicle::getWeight(){
	return this->weight;
}

int Vehicle::getPassengers(){
	return this->passengers;
}

std::string Vehicle::getType() {
	std::stringstream ss;
	if(this->isCargo) {
		ss << "Cargo";
	}
	else {
		ss << "Passenger";
	}
	ss << " " << this->transportType;
	return ss.str();
}

void Vehicle::setCapacity(int capacity) {
	this->capacity = capacity;
	if(capacity <= 18){
		this->transportType = "Car";
	}
	else this->transportType = "Bus";
}

int Vehicle::getCapacity() {
	return this->capacity;
}

#include "Plane.h"

Plane::Plane(int capacity) {
	this->capacity = capacity;
	this->isCargo = false;
	this->passengers = 2;
	this->weight = 0;
}

void Plane::setNumPassenger(int pass) {
	this->passengers = pass;
	this->isCargo = false;
	this->weight = 0;
	this->transportType = "Passenger Plane";
}

void Plane::setCargoWeight(float weight) {
	this->weight = weight;
	this->isCargo = true;
	this->passengers = 2;
	this->transportType = "Cargo Plane";
}

float Plane::travel(Stops* stop, RouteNode* head, bool best) {
	MapIterator* iter = new MapIterator(head);
	float distance = 0;
	if(best){
		//would skip symbols 'T' in the route
		while(iter->currentNode() == nullptr && iter->operator*() != stop){
			if(iter->operator*()->getSymbol() == 'T'){
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

std::string Plane::getType() {
	return this->transportType;
}

void Plane::setCapacity(int capacity) {
	this->capacity = capacity;
}

int Plane::getCapacity() {
	return this->capacity;
}

int Plane::getPassengers() {
	return this->passengers;
}

float Plane::getWeight() {
	return this->weight;
}

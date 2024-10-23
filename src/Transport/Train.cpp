#include "Train.h"

Train::Train(int capacity) {
	this->capacity = capacity;
	this->isCargo = false;
	this->passengers = 1;
	this->weight = 0;
}

void Train::setNumPassenger(int pass) {
	this->passengers = pass;
	this->isCargo = false;
	this->weight = 0;
	this->transportType = "Passenger Train";
}

float Train::getWeight(){
	return this->weight;
}

int Train::getPassengers(){
	return this->passengers;
}

void Train::setCargoWeight(float weight) {
	this->weight = weight;
	this->isCargo = true;
	this->passengers = 1;
	this->transportType = "Cargo Train";
}

float Train::travel(Stops* stop, RouteNode* head, bool best) {
	MapIterator* iter = new MapIterator(head);
	float distance = 0;
	if(best){
		//would skip symbols 'R" and 'A' in the route
		while(iter->currentNode() == nullptr && iter->operator*() != stop){
			if(iter->operator*()->getSymbol() == 'R' || iter->operator*()->getSymbol() == 'A'){
				++iter;
				continue;
			}
			distance += iter->operator*()->getDistance();
			++iter;
		}
	}else{
		while( iter->currentNode() == nullptr && iter->operator*() != stop){
			if(iter->operator*()->getSymbol() == 'A'){
				++iter;
				continue;
			}
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

std::string Train::getType() {
	return this->transportType;
}

void Train::setCapacity(int capacity) {
	this->capacity = capacity;
}

int Train::getCapacity() {
	return this->capacity;
}

#include <exception>
#include <vector>
using namespace std;

#include "ResourceMediator.h"
#include "Resources.h"
#include "CitySector.h"

ResourceMediator::ResourceMediator(vector<Resources*> aResources) {
}

bool ResourceMediator::usePower(double aUnits, CitySector aSender) {
	throw "Not yet implemented";
}

void ResourceMediator::replenishPower(double aUnits) {
	throw "Not yet implemented";
}

bool ResourceMediator::useRevenue(double aUnits, CitySector aSender) {
	throw "Not yet implemented";
}

void ResourceMediator::replenishRevenue(double aUnits) {
	throw "Not yet implemented";
}

bool ResourceMediator::useWater(double aUnits, CitySector aSender) {
	throw "Not yet implemented";
}

void ResourceMediator::replenishWater(double aUnits) {
	throw "Not yet implemented";
}

bool ResourceMediator::cleanWaste(double aUnits, CitySector aSender) {
	throw "Not yet implemented";
}

void ResourceMediator::gainWaste(double aUnits) {
	throw "Not yet implemented";
}

bool ResourceMediator::cleanSewage(double aUnits, CitySector aSender) {
	throw "Not yet implemented";
}

void ResourceMediator::gainSewage(double aUnits) {
	throw "Not yet implemented";
}

void ResourceMediator::outOfPower() {
	throw "Not yet implemented";
}

void ResourceMediator::outOfWater() {
	throw "Not yet implemented";
}

void ResourceMediator::outOfRevenue() {
	throw "Not yet implemented";
}

void ResourceMediator::outOfWasteMan() {
	throw "Not yet implemented";
}

void ResourceMediator::outOfSewageMan() {
	throw "Not yet implemented";
}


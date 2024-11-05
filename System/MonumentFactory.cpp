#include "MonumentFactory.h"
#include "ResidentialBuilding.h"
#include "Monument.h"

Buildings* MonumentFactory::createBuilding()
{
    Buildings* temp = new Monument("monument",500,500,564.50,600,800);
	return  temp;
}
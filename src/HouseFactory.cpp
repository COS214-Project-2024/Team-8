#include "HouseFactory.h"
#include "ResidentialBuilding.h"
#include "House.h"

Buildings* HouseFactory::createBuilding()
{
    Buildings* temp = new House("house", 500,600,5600,345,500,1000);
	return  temp;
}


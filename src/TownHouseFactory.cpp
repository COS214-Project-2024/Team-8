#include "TownHouseFactory.h"
#include "ResidentialBuilding.h"
#include "TownHouse.h"

Buildings* TownHouseFactory::createBuilding()
{
    Buildings* temp = new TownHouse("TownHouse", 500,600,5600,345,500,1000);
	return  temp;
}
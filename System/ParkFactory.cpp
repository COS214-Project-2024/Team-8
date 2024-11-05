#include "ParkFactory.h"
#include "ResidentialBuilding.h"
#include "Park.h"

Buildings* ParkFactory::createBuilding()
{
    Buildings* temp = new Park("park",500,500,564.50,600,800);
	return  temp;
}
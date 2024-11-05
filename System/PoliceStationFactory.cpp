#include "PoliceStationFactory.h"
#include "PublicServiceBuilding.h"
#include "PoliceStation.h"

Buildings* PoliceStationFactory::createBuilding()
{
    Buildings* temp = new PoliceStation("PoliceStation",500,500,564.50,600,800,600,5600);
	return  temp;
}
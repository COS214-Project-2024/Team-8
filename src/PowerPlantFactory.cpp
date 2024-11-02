#include "PowerPlantFactory.h"
#include "ResidentialBuilding.h"
#include "PowerPlant.h"

Buildings* PowerPlantFactory::createBuilding()
{
    Buildings* temp = new PowerPlant("PowerPlant", 500,600,5600,345,500,1000);
	return  temp;
}
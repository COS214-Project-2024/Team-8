#include "FactoriesFactory.h"
#include "ResidentialBuilding.h"
#include "Factories.h"

Buildings* FactoriesFactory::createBuilding()
{
    Buildings* temp = new Factories("Factories", 500,600,5600,345,500,1000);
	return  temp;
}
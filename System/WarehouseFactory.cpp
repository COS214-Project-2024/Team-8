#include "WarehouseFactory.h"
#include "ResidentialBuilding.h"
#include "Warehouse.h"

Buildings* WarehouseFactory::createBuilding()
{
    Buildings* temp = new Warehouse("TownHouse", 500,600,5600,345,500,1000);
	return  temp;
}
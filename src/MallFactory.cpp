#include "MallFactory.h"
#include "ResidentialBuilding.h"
#include "Mall.h"

Buildings* MallFactory::createBuilding()
{
    Buildings* temp = new Mall("mall",500,500,564.50,600,800,50.0,5600.50,500);
	return  temp;
}
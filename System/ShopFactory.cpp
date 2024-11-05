#include "ShopFactory.h"
#include "ResidentialBuilding.h"
#include "Shop.h"

Buildings* ShopFactory::createBuilding()
{
    Buildings* temp = new Shop("shop",500,500,564.50,600,800,50.0,5600.50,500);
	return  temp;
}
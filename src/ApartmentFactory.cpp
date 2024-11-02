#include "ApartmentFactory.h"
#include "ResidentialBuilding.h"
#include "Apartment.h"

Buildings* ApartmentFactory::createBuilding()
{
    Buildings* temp = new Apartment("apartment", 500,600,5600,345,500,1000);
	return  temp;
}
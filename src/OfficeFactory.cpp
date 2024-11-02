#include "OfficeFactory.h"
#include "ResidentialBuilding.h"
#include "Office.h"

Buildings* OfficeFactory::createBuilding()
{
    Buildings* temp = new Office("office",500,500,546.50,600,700,546.90,450000.60,600,600000);
	return  temp;
}
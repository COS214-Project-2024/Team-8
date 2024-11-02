#include "CulturalCenterFactory.h"
#include "ResidentialBuilding.h"
#include "CulturalCenter.h"

Buildings* CulturalCenterFactory::createBuilding()
{
    Buildings* temp = new CulturalCenter("cultural center",500,500,564.50,600,800);
	return  temp;
}
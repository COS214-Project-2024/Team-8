#include "MedicalCenterFactory.h"
#include "PublicServiceBuilding.h"
#include "MedicalCenter.h"

Buildings* MedicalCenterFactory::createBuilding()
{
    Buildings* temp = new MedicalCenter("medical center",500,500,564.50,600,800,600,5600);
	return  temp;
}
#include "SchoolFactory.h"
#include "PublicServiceBuilding.h"
#include "School.h"

Buildings* SchoolFactory::createBuilding()
{
    Buildings* temp = new School("school",500,500,564.50,600,800,600,5600);
	return  temp;
}
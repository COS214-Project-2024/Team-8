using namespace std;

#ifndef __Resources_h__
#define __Resources_h__

// #include "Utility.h"
// #include "Buildings.h"
#include "powerResource.h"
#include "waterResource.h"
#include "revenueResource.h"
#include "wasteManagmentResource.h"
#include "sewageManagmentResource.h"

class Utility;
class Buildings;
// class powerResource;
// class waterResource;
// class revenueResource;
// class wasteManagmentResource;
// class sewageManagmentResource;
class Resources;

class Resources: public powerResource, public waterResource, public revenueResource, public wasteManagmentResource, public sewageManagmentResource
{
	private: Utility* _citySector;
	public: Buildings* _unnamed_Buildings_;
	public: Utility* _unnamed_Utility_;

	public: virtual bool giveResource(double aUnits) = 0;

	public: virtual void receiveResource(int aUnits) = 0;

	public: virtual void outOfResources() = 0;
};

#endif

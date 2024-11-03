using namespace std;

#ifndef __Resources_h__
#define __Resources_h__

// #include "ResourceMediator.h"
// #include "Buildings.h"
#include "powerResource.h"
#include "waterResource.h"
#include "revenueResource.h"
#include "wasteManagmentResource.h"
#include "sewageManagmentResource.h"

class ResourceMediator;
class Buildings;
// class powerResource;
// class waterResource;
// class revenueResource;
// class wasteManagmentResource;
// class sewageManagmentResource;
class Resources;

class Resources: public powerResource, public waterResource, public revenueResource, public wasteManagmentResource, public sewageManagmentResource
{
	private: ResourceMediator* _citySector;
	public: Buildings* _unnamed_Buildings_;
	public: ResourceMediator* _unnamed_ResourceMediator_;

	public: virtual bool giveResource(double aUnits) = 0;

	public: virtual void receiveResource(int aUnits) = 0;

	public: virtual void outOfResources() = 0;
};

#endif

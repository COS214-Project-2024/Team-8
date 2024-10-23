#include <exception>
using namespace std;

#ifndef __revenueResource_h__
#define __revenueResource_h__

class revenueResource;

class revenueResource
{
	private: double _availableRevenue;

	public: bool giveRevenue(int aUnits);

	public: void receiverRevenue(int aUnits);
};

#endif

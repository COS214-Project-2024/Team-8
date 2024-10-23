#include <exception>
using namespace std;

#ifndef __waterResource_h__
#define __waterResource_h__

class waterResource;

class waterResource
{
	private: int _availableWater;

	public: bool giveWater(int aUnits);

	public: void recieveWater(int aUnits);
};

#endif

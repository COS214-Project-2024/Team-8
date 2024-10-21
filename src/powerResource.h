#include <exception>
using namespace std;

#ifndef __powerResource_h__
#define __powerResource_h__

class powerResource;

class powerResource
{
	private: int _availablePower;

	public: bool givePower(int aUnits);

	public: void recievePower(int aUnits);
};

#endif

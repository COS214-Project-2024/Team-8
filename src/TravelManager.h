#include <exception>
using namespace std;

#ifndef __TravelManager_h__
#define __TravelManager_h__

// #include "Transport.h"
// #include "City.h"
// #include "Stops.h"

class Transport;
class City;
class Stops;
class TravelManager;

class TravelManager
{
	private: Transport* _transport;
	public: City* _unnamed_City_;
	public: Transport* _unnamed_Transport_;
	public: Stops* _unnamed_Stops_;

	public: void travelManager();

	public: bool travel(Stops* aDestination, int aTransType, bool aCargo);

	public: ~TravelManager();
};

#endif

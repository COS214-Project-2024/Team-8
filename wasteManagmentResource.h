#include <exception>
using namespace std;

#ifndef __wasteManagmentResource_h__
#define __wasteManagmentResource_h__

class wasteManagmentResource;

class wasteManagmentResource
{
	private: int _availableWasteManagment;

	public: bool giveWasteManagement(int aUnits);

	public: void recieveWaste(int aUnits);
};

#endif

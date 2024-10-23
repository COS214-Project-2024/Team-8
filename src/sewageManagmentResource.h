#include <exception>
using namespace std;

#ifndef __sewageManagmentResource_h__
#define __sewageManagmentResource_h__

class sewageManagmentResource;

class sewageManagmentResource
{
	private: int _availableSewageMan;

	public: bool giveSewageMan(int aUnits);

	public: void recieveSewage(int aUnits);
};

#endif

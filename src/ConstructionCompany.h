#include <exception>
using namespace std;

#ifndef __ConstructionCompany_h__
#define __ConstructionCompany_h__

// #include "Buildings.h"

class Buildings;
class ConstructionCompany;

class ConstructionCompany
{
	private: Buildings* _buildings;
	public: Buildings* _unnamed_Buildings_;

	public: void construct();
};

#endif

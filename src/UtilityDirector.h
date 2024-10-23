#include <exception>
using namespace std;

#ifndef __UtilityDirector_h__
#define __UtilityDirector_h__

// #include "UtilityBuilder.h"

class UtilityBuilder;
class UtilityDirector;

class UtilityDirector
{
	private: UtilityBuilder* _creator;
	public: UtilityBuilder* _unnamed_UtilityBuilder_;

	public: void construct();
};

#endif

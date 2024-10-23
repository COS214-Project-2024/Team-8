#include <exception>
using namespace std;

#ifndef __Policies_h__
#define __Policies_h__

// #include "Government.h"

class Government;
class Policies;

__abstract class Policies
{
	public: Government* _unnamed_Government_;

	public: virtual void executePolicy() = 0;
};

#endif

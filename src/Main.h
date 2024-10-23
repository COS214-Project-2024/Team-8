#include <exception>
using namespace std;

#ifndef __Main_h__
#define __Main_h__

// #include "UtilitiesSector.h"

class UtilitiesSector;
class Main;

__abstract class Main
{
	public: UtilitiesSector* _unnamed_UtilitiesSector_;

	public: virtual void handleRequest() = 0;
};

#endif

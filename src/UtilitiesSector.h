#include <exception>
using namespace std;

#ifndef __UtilitiesSector_h__
#define __UtilitiesSector_h__

// #include "Main.h"

class Main;
class UtilitiesSector;

__abstract class UtilitiesSector
{
	public: Main* _unnamed_Main_;

	public: virtual void handleRequest() = 0;
};

#endif

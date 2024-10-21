#include <exception>
using namespace std;

#ifndef __FinanceSection_h__
#define __FinanceSection_h__

#include "Government.h"

// class Government;
class FinanceSection;

__abstract class FinanceSection: public Government
{

	public: virtual void handleRequest() = 0;
};

#endif

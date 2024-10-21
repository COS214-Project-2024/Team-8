#include <exception>
using namespace std;

#ifndef __CommComponent_h__
#define __CommComponent_h__

// #include "Mall.h"

// class Mall;
class CommComponent;

__abstract class CommComponent
{
	public: Mall* _unnamed_Mall_;

	public: virtual void add(EstateComponent aParam) = 0;

	public: virtual void remove(EstateComponent aParam) = 0;

	public: virtual void getChild(EstateComponent aParam) = 0;
};

#endif

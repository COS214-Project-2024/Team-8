#include <exception>
using namespace std;

#ifndef __EstateComponent_h__
#define __EstateComponent_h__

// #include "Estate.h"

// class Estate;
class EstateComponent;

__abstract class EstateComponent
{
	public: Estate* _unnamed_Estate_;

	public: virtual void add(EstateComponent aParam) = 0;

	public: virtual void remove(EstateComponent aParam) = 0;

	public: virtual void getChild(EstateComponent aParam) = 0;
};

#endif

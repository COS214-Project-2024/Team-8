#include <exception>
using namespace std;

#ifndef __Estate_h__
#define __Estate_h__

#include "EstateComponent.h"

// class EstateComponent;
class Estate;

class Estate: public EstateComponent
{
	private: EstateComponent _children;
	public: EstateComponent* _unnamed_EstateComponent_;

	public: void add(EstateComponent aParam);

	public: void remove(EstateComponent aParam);

	public: void getChild(EstateComponent aParam);
};

#endif

#include <exception>
using namespace std;

#ifndef __Teacher_h__
#define __Teacher_h__

#include "Citizen.h"

// class Citizen;
class Teacher;

class Teacher: public Citizen
{

	public: Citizen* clone();

	public: void update();
};

#endif

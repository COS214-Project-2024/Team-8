#include <exception>
using namespace std;

#ifndef __PoliceOfficer_h__
#define __PoliceOfficer_h__

// #include "Doctor.h"

class Doctor;
class PoliceOfficer;

class PoliceOfficer
{
	public: Doctor* _unnamed_Doctor_;

	public: Citizen* clone();

	public: void update();
};

#endif

#include <exception>
using namespace std;

#ifndef __Doctor_h__
#define __Doctor_h__

// #include "PoliceOfficer.h"

class PoliceOfficer;
class Doctor;

class Doctor
{
	public: PoliceOfficer* _unnamed_PoliceOfficer_;

	public: Citizen* clone();

	public: void update();
};

#endif

#include <exception>
#include <string>
using namespace std;

#ifndef __Citizen_h__
#define __Citizen_h__

// #include "City.h"
// #include "Government.h"
// #include "PublicServicesPolicies.h"
// #include "EconomicPolicies.h"
// #include "PopulationControl.h"
// #include "Transport.h"

class City;
class Government;
class PublicServicesPolicies;
class EconomicPolicies;
class PopulationControl;
class Transport;
class Citizen;

__abstract class Citizen
{
	private: int _age;
	private: string _name;
	private: double _salary;
	private: double _satisfaction;
	public: City* _prototype;
	public: Government* _citizenList;
	public: Government* _requestee;
	public: PublicServicesPolicies* _unnamed_PublicServicesPolicies_;
	public: EconomicPolicies* _unnamed_EconomicPolicies_;
	public: PopulationControl* _unnamed_PopulationControl_;
	public: Transport* _unnamed_Transport_;

	public: void citizen(int aAge, string aName, double aSalary);

	public: int getAge();

	public: string getName();

	public: double getSalary();

	public: double getSatisfaction();

	public: virtual Citizen* clone() = 0;

	public: virtual void update() = 0;
};

#endif

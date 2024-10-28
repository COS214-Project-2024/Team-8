#include <exception>
#include <string>
using namespace std;

#ifndef CITIZEN_H
#define CITIZEN_H

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

class Citizen
{

	private:
    int age;
    std::string name;
    double salary;
    double satisfaction;
    double balance; //---------------------------HEY I'M NEW HERE-------------------------------------- 

protected:
    // Protected constructor for abstract class
    Citizen(std::string name, int age, double salary);

	
	public: City* _prototype;
	public: Government* _citizenList;
	public: Government* _requestee;
	public: PublicServicesPolicies* _unnamed_PublicServicesPolicies_;
	public: EconomicPolicies* _unnamed_EconomicPolicies_;
	public: PopulationControl* _unnamed_PopulationControl_;
	public: Transport* _unnamed_Transport_;

	public:
    virtual ~Citizen() = default;

    int getAge() const;
    std::string getName() const;
    std::string typeOfCitizen() const;
    double getSalary() const;
    double getSatisfaction() const;
    void setSalary(double s);
    void setBalance(double s); //---------------------------HEY I'M NEW HERE-------------------------------------- 
    double getBalance();//---------------------------HEY I'M NEW HERE-------------------------------------- 
    void setSatisfaction(double s);
    virtual double calculateTax() const = 0;
    virtual Citizen* clone() = 0;
    virtual void update() = 0;
};

#endif
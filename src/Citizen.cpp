#include <exception>
#include <string>
using namespace std;

#include "Citizen.h"
// Temporarily comment these until their issues are fixed
// #include "City.h"
// #include "Government.h"
// #include "PublicServicesPolicies.h"
// #include "EconomicPolicies.h"
// #include "PopulationControl.h"
// #include "Transport.h"

// Fixed initialization order to match declaration order in header
Citizen::Citizen(std::string aName, int aAge, double aSalary) 
    : age(aAge),              // Match header order: age first
      name(aName),            // then name
      salary(aSalary),        // then salary
      satisfaction(100.0)     // then satisfaction
{
}

int Citizen::getAge() const {
    return age;
}

string Citizen::getName() const {
    return name;
}

double Citizen::getSalary() const {
    return salary;
}

double Citizen::getSatisfaction() const {
    return satisfaction;
}

void Citizen::setSalary(double s) {
    salary = s;
}

void Citizen::setSatisfaction(double s) {
    satisfaction = s;
}
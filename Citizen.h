#ifndef CITIZEN_H
#define CITIZEN_H

class Citizen
{
private:
    /* data */
    bool isEmployed ; 
    bool ownsProperty ; 
    double satisfaction ; 
    float currTaxRate ; 
    float salary ; 
public:
    Citizen(/* args */);
    ~Citizen();

    bool isCitizenEmployed() ; 
    bool isCitizenPropertyOwner() ; 
    double getSatisfaction() ; 
    float getSalary() ; 
    float getCurrTaxRate() ; 

};

Citizen::Citizen(/* args */)
{
}

Citizen::~Citizen()
{
}

inline bool Citizen::isCitizenEmployed()
{
    return this->isEmployed;
}

inline bool Citizen::isCitizenPropertyOwner()
{
    return this->ownsProperty ;
}

inline double Citizen::getSatisfaction()
{
    return satisfaction;
}

inline float Citizen::getSalary()
{
    return this->salary;
}

inline float Citizen::getCurrTaxRate()
{
    return this->currTaxRate;
}

#endif
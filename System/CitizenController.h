#ifndef CITIZENCONTROLLER_H
#define CITIZENCONTROLLER_H

#include "Citizen.h"

class CitizenController
{
private:
    /* data */
    Citizen ** ListOfCitizens ; 
    int amountOfCitizens ; 
    int amountEmployedCitizens ;
    int amountPropertyOwners ; 

    int AvgSatisfaction ; 

    float TaxableIncome ; 

public:
    CitizenController();
    ~CitizenController();

    void addCitizen(Citizen * add) ;
    void removeCitizen(Citizen * rem) ;

    int getAmountOfCitizens() ; 
    int getEmployedCitizensAmount() ; 
    int getamountPropertyOwnersAmount() ; 

    double getAvgSatisfaction() ;
    float GetTaxableIncome() ;

    Citizen** getListOfCitizens() ;   

};

#endif

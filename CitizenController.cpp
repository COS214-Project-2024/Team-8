#ifndef CITIZENCONTROLLER_CPP
#define CITIZENCONTROLLER_CPP

#include "CitizenController.h"

CitizenController::CitizenController(/* args */)
{
}

CitizenController::~CitizenController()
{
}

void CitizenController::addCitizen(Citizen *add)
{
    if ( this->amountOfCitizens == 0)
    {
        this->ListOfCitizens = new Citizen * [1] ; 
        this->ListOfCitizens[0] = add ; 
        this->amountOfCitizens++ ; 

    }
        else
    {
        Citizen** newListOfCitizen = new Citizen*[this->amountOfCitizens + 1];
        
        for (int i = 0; i < this->amountOfCitizens; i++)
        {
            newListOfCitizen[i] = this->ListOfCitizens[i];
        }

        newListOfCitizen[this->amountOfCitizens] = add;

        delete[] this->ListOfCitizens;

        this->ListOfCitizens = newListOfCitizen;
        this->amountOfCitizens++;
    }
}

void CitizenController::removeCitizen(Citizen *rem)
{
        if (this->amountOfCitizens == 0) 
    {
        return; 
    }

    int indexToRemove = -1;
    for (int i = 0; i < this->amountOfCitizens; i++)
    {
        if (this->ListOfCitizens[i] == rem)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) 
    {
        return; 
    }

    Citizen **newListOfCitizen = new Citizen*[this->amountOfCitizens - 1];

    for (int i = 0, j = 0; i < this->amountOfCitizens; i++)
    {
        if (i != indexToRemove) 
        {
            newListOfCitizen[j++] = this->ListOfCitizens[i];
        }
    }

    delete[] this->ListOfCitizens;

    this->ListOfCitizens = newListOfCitizen;
    this->amountOfCitizens--;
}

int CitizenController::getAmountOfCitizens()
{
    return this->amountOfCitizens ; 
}

int CitizenController::getEmployedCitizensAmount()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfCitizens ; i ++)
    {
        if ( this->ListOfCitizens[i]->getEmployementStatus() == true)
        {
            Res++ ; 
        }
    }
    this->amountEmployedCitizens = Res ; 
    return Res ; 
}

int CitizenController::getamountPropertyOwnersAmount()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfCitizens ; i ++)
    {
        if ( this->ListOfCitizens[i]->getPropertyOwnershipStatus() == true)
        {
            Res++ ; 
        }
    }
    this->amountPropertyOwners = Res ; 
    return Res ; 
}

double CitizenController::getAvgSatisfaction()
{
    double Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfCitizens ; i ++)
    {
        Res += this->ListOfCitizens[i]->getSatisfaction() ; 
    }

    this->AvgSatisfaction = Res / this->amountOfCitizens ; 
    return this->AvgSatisfaction ; 

}

float CitizenController::GetTaxableIncome()
{
    float Salary = 0 ; 
    float TaxRate = 0  ; 
    for ( int i = 0 ; i < this->amountOfCitizens ; i ++)
    {
        this->TaxableIncome += ( this->ListOfCitizens[i]->getSalary() * this->ListOfCitizens[i]->getTaxRate() ) ; // Is the Tax rate format 0.4 or 40 ? For now , taking it as 0.4
    }

    return this->TaxableIncome ; 

}

Citizen **CitizenController::getListOfCitizens() // DIDNT MAKE THIS DEEP COPY FOR MEMORY PURPOSES . BE ADVISED
{
    return this->ListOfCitizens ;
}

#endif
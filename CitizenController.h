#ifndef CITIZENCONTROLLER_H
#define CITIZENCONTROLLER_H

#include "Citizen.h"

class CitizenController
{
private:
    /* data */
    /**
     * @class CitizenController
     * @brief Lists of Citizens
     * Class uses a list of Citizens to loop through each Citizen to acquire data
     */
    Citizen **ListOfCitizens;
    /**
     * @class amountOfCitizens
     * @brief Amount of Citizens in the list
     * Variable to hold the amount of Citizens To loop through the list
     */
    int amountOfCitizens;
    /**
     * @class amountEmployedCitizens
     * @brief Amount of Employed Citizens
     * Shows the number of employed citizens in the city
     */
    int amountEmployedCitizens;
    /**
     * @class amountPropertyOwners
     * @brief Amount of Property Owners Citizens
     * Shows the number of Property Owners in the city
     */
    int amountPropertyOwners;
    /**
     * @class AvgSatisfaction
     * @brief Average Satisfaction of the Citizens
     * Holds the average satisfaction of the citizens
     * Thus the player can see the happinness of the city
     */
    int AvgSatisfaction;
    /**
     * @class TaxableIncome
     * @brief Taxable Income of the Citizens
     * The Amount of Taxes that the Citizens pay
     * This variable is used with the Income from Commercial Buildings
     */
    float TaxableIncome;

public:
    CitizenController();
    ~CitizenController();
    /**
     * @class addCitizen
     * @brief Adds a Citizen too a list
     * Adds the Citizen to the list to be used by the Interface
     */
    void addCitizen(Citizen *add);
    /**
     * @class removeCitizen
     * @brief Removes A Citizen From the List
     * Removes the Citizen from the list.
     * This could be due to either the Citizen leaves the city or the Citizen passed away
     */
    void removeCitizen(Citizen *rem);

    /**
     * @class getAmountOfCitizens
     * @brief Returns the size of the List
     * Returns the size of The citizen list in order for the player to see the
     * maximum population of the city
     */
    int getAmountOfCitizens();
    /**
     * @class getEmployedCitizensAmount
     * @brief Returns the amount of the Employed Citizens
     * Returns the size of The citizen that holds employment
     */
    int getEmployedCitizensAmount();
        /**
     * @class getamountPropertyOwnersAmount
     * @brief Returns the amount of the Property Owners
     * Returns the size of The citizen that holds Property
     */
    int getamountPropertyOwnersAmount();
    /**
     * @class getAvgSatisfaction
     * @brief Returns the average satisfaction of the city
     * Loops through the list and adds the amount of Satisfaction , afterwards divides by the population of the city 
     * Returns the new amount back to the City for the Player to see
     */
    double getAvgSatisfaction();
    /**
     * @class GetTaxableIncome
     * @brief Returns the total Taxable Income of the city
     * Loops through the list and adds the amount of Taxable Income from the Citizens
     * This value is added with Commercial Income to see the Income of the Funds .
     */
    float GetTaxableIncome();
    /**
     * @class getListOfCitizens
     * @brief Returns the list Of Citizens
     * Function returns the list of Citizens .
     * This is here if any functions above the City wants to be able to use the Citizens
     */
    Citizen **getListOfCitizens();
};

#endif

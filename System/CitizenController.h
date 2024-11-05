#ifndef CITIZENCONTROLLER_H
#define CITIZENCONTROLLER_H

#include "Citizen.h"

/**
 * @class CitizenController
 * @brief A class to manage and control a collection of citizens.
 * 
 * The CitizenController class manages a list of citizens and provides functionality to 
 * add, remove, and retrieve information about citizens. It also keeps track of statistics 
 * like employment, property ownership, satisfaction, and taxable income.
 */
class CitizenController
{
private:
    Citizen ** ListOfCitizens; ///< A dynamic array of pointers to Citizen objects.
    int amountOfCitizens; ///< The current number of citizens in the list.
    int amountEmployedCitizens; ///< The number of employed citizens in the list.
    int amountPropertyOwners; ///< The number of property owners in the list.

    int AvgSatisfaction; ///< The average satisfaction score of the citizens.
    float TaxableIncome; ///< The total taxable income of all citizens combined.

public:
    /**
     * @brief Default constructor for the CitizenController class.
     * 
     * Initializes internal variables and allocates memory for the list of citizens.
     */
    CitizenController();

    /**
     * @brief Destructor for the CitizenController class.
     * 
     * Cleans up dynamically allocated memory (e.g., deletes the list of citizens).
     */
    ~CitizenController();

    /**
     * @brief Adds a new citizen to the list.
     * 
     * This method adds a new Citizen object to the dynamic array and updates statistics 
     * like the total number of citizens, employed citizens, and property owners.
     * 
     * @param add A pointer to the Citizen object to be added.
     */
    void addCitizen(Citizen * add);

    /**
     * @brief Removes a citizen from the list.
     * 
     * This method removes a Citizen object from the dynamic array and updates statistics 
     * accordingly (e.g., reducing the number of employed citizens or property owners).
     * 
     * @param rem A pointer to the Citizen object to be removed.
     */
    void removeCitizen(Citizen * rem);

    /**
     * @brief Gets the total number of citizens in the list.
     * 
     * This method returns the current count of citizens in the list.
     * 
     * @return The number of citizens (int).
     */
    int getAmountOfCitizens();

    /**
     * @brief Gets the number of employed citizens in the list.
     * 
     * This method returns the current count of employed citizens in the list.
     * 
     * @return The number of employed citizens (int).
     */
    int getEmployedCitizensAmount();

    /**
     * @brief Gets the number of property owners in the list.
     * 
     * This method returns the current count of property owners in the list.
     * 
     * @return The number of property owners (int).
     */
    int getamountPropertyOwnersAmount();

    /**
     * @brief Gets the average satisfaction score of all citizens.
     * 
     * This method calculates and returns the average satisfaction score of all citizens 
     * in the list. It may return a value between 0 and 100, representing satisfaction 
     * as a percentage.
     * 
     * @return The average satisfaction score (double).
     */
    double getAvgSatisfaction();

    /**
     * @brief Gets the total taxable income of all citizens.
     * 
     * This method calculates and returns the total taxable income from all citizens combined.
     * 
     * @return The total taxable income (float).
     */
    float GetTaxableIncome();

    /**
     * @brief Gets a pointer to the list of citizens.
     * 
     * This method returns the current list of Citizen objects.
     * 
     * @return A pointer to an array of Citizen pointers.
     */
    Citizen** getListOfCitizens();
};


#endif

#ifndef UTILITIESCONTROL_H
#define UTILITIESCONTROL_H

#include "CitySector.h"
#include "Utility.h"
#include "UtilityPowerPlant.h"
#include "WaterSupply.h"
#include "WasteManagement.h"
#include "SewageSystems.h"

/**
 * @class UtilitiesControl
 * @brief A class to manage a collection of utilities (e.g., water, sewage, power, waste).
 * 
 * This class manages a dynamic array of Utility objects and provides methods to add,
 * remove, and get total values of various utilities.
 */
class UtilitesControl
{
private:
    Utility ** ListOfUtilites; ///< A dynamic array of pointers to Utility objects.
    int amountOfUtil; ///< The current number of Utility objects in the array.

public:
    /**
     * @brief Default constructor for the UtilitiesControl class.
     * 
     * Initializes the internal array for utilities and sets the amount of utilities to 0.
     */
    UtilitesControl();

    /**
     * @brief Destructor for the UtilitiesControl class.
     * 
     * Cleans up any dynamically allocated memory (e.g., deletes the array of utilities).
     */
    ~UtilitesControl();

    /**
     * @brief Gets the total power usage from all utilities.
     * 
     * This method iterates through the list of utilities and sums up their individual power usage.
     * 
     * @return The total power usage (int).
     */
    int getTotalPower();

    /**
     * @brief Gets the total sewage usage from all utilities.
     * 
     * This method iterates through the list of utilities and sums up their individual sewage usage.
     * 
     * @return The total sewage usage (int).
     */
    int getTotalSewage();

    /**
     * @brief Gets the total waste produced by all utilities.
     * 
     * This method iterates through the list of utilities and sums up their individual waste production.
     * 
     * @return The total waste produced (int).
     */
    int getTotalWaste();

    /**
     * @brief Gets the total water usage from all utilities.
     * 
     * This method iterates through the list of utilities and sums up their individual water usage.
     * 
     * @return The total water usage (int).
     */
    int getTotalWater();

    /**
     * @brief Adds a new utility to the list.
     * 
     * This method adds a new utility to the dynamic array of utilities, expanding the array if necessary.
     * 
     * @param add A pointer to the Utility object to be added.
     */
    void addUtilities(Utility * add);

    /**
     * @brief Removes a utility from the list.
     * 
     * This method removes the specified utility from the dynamic array of utilities and adjusts the array size.
     * 
     * @param rem A pointer to the Utility object to be removed.
     */
    void removeUtilities(Utility * rem);

    /**
     * @brief Gets the current number of utilities in the list.
     * 
     * This method returns the current count of the utility objects in the list.
     * 
     * @return The number of utilities (int).
     */
    int getAmountOfUtilities();
};


#endif

#ifndef BUILDINGCONTROLLER_H
#define BUILDINGCONTROLLER_H

#include "Citizen.h"
#include "Buildings.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"

#include <iostream>

class BuildingController
{
private:
    /**
     * @class ListOfBuildings
     * @brief Lists of Buildings
     * Class uses a list of Buildings to loop through each Building to acquire data
     */
    Buildings **ListOfBuildings;
    /**
     * @class amountOfBuildings
     * @brief Amount of Buildings in the list
     * Variable to hold the amount of Buildings To loop through the list
     */
    int amountOfBuildings;

public:
    BuildingController(/* args */);
    ~BuildingController();
    /**
     * @class addBuilding
     * @brief Adds a Building to the list
     * Adds the Building to the list to be used by the Interface
     */
    void addBuilding(Buildings *add);
    /**
     * @class removeBuilding
     * @brief Removes A Building From the List
     * Removes the Building from the list.
     */
    void removeBuilding(Buildings *rem);
    /**
     * @class getAmountOfBuildings
     * @brief Returns the amount of Buildings
     * Returns the amount of Buildings in the list
     * The Player could see the amount of Buildings in the city for clarity
     */
    int getAmountOfBuildings();

    /**
     * @class getTotalPowerReq
     * @brief Returns the total amount of Power Requirment
     * Returns the amount of Power Requirment in the City
     * The Player could see the amount of Power that the city needs
     *
     */
    int getTotalPowerReq();
    /**
     * @class getTotalSewageReq
     * @brief Returns the total amount of Sewage Requirment
     * Returns the amount of Sewage Requirment in the City
     * The Player could see the amount of Sewage Managment that the city needs
     *
     */
    int getTotalSewageReq();
    /**
     * @class getTotalWasteReq
     * @brief Returns the total amount of Waste Managment Requirment
     * Returns the amount of Waste Managment that the City can Handle .
     * The Player could see the amount of Sewage Managment that the city needs
     */
    int getTotalWasteReq();
    /**
     * @class getTotalWaterReq
     * @brief Returns the total amount of Water Requirment 
     * Returns the amount of Water Requirment that the City needs .
     * The Player could see the amount of Water that the city needs .
     */
    int getTotalWaterReq();
    /**
     * @class getMaintenanceCost
     * @brief Returns the amount of Maintenance cost for the Buildings
     * Returns the amount of Maintenance Funds that all the Buildings in the city needs to stay operational 
     * The Player could see the Total Mainenance cost of the City
     */
    int getMaintenanceCost();
    /**
     * @class getListOfCitizens
     * @brief Returns a List of Citizens in a Residential Building
     * Loops through the list and returns a list of all the Citizens that is inside of homes .
     */
    Citizen **getListOfCitizens();
    /**
     * @class getCommercialIncome
     * @brief Returns the amount of Commerce that the Commercial Buildings Generate
     * Returns the amount of Income That the Commercial Buildings Generate 
     * Is used in unisen with the Taxable Income to see the total amount of Income the City Generates
     */
    int getCommercialIncome();
};

#endif
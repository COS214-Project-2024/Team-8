#ifndef CITYCONTROLLER_H
#define CITYCONTROLLER_H

#include "Buildings.h"
#include "PopulationControl.h"
#include "Resource.h"
#include "Policies.h"
#include "Citizen.h"
#include "UtilitesControl.h"
#include "BuildingController.h"
#include "CitizenController.h"

class CityController
{
private:
    /* data */

    /**
     * @class UtilitesControl
     * @brief Controls a List of Utilities
     *
     * This interface provides a common structure for all Utilities related functions
     * Is in charge of getting the total amount of Power , Sewage , Water and Waste Supply
     */
    UtilitesControl ManagmentOfUtilities;
    /**
     * @class BuildingController
     * @brief Controls a List of Buildings
     *
     * This interface provides a common structure for all Buildings related functions
     * Is in charge of getting the total amount of Power , Sewage , Water and Waste Requirment of the Buildings
     */
    BuildingController ManagmentOfBuildings;
    /**
     * @class CitizenController
     * @brief Controls a List of Citizens
     *
     * This interface provides a common structure for all Citizen related functions
     * Is in charge of getting the total amount Employed and Property Owners , aswell as Citizens Tax Rate and the Average Satisfaction of all the citizens .
     */
    CitizenController ManagmentOfCitizens;

public:
    CityController();
    ~CityController();

    void Update();
    Policies *evaluatePolicies();
    Citizen *handleCitizenNeedsAndSatisfaction();
    PopulationControl *evaluatePopulationControl();
    void addDecorations(); // What Decorations and where ? City Sectors ?
    void ProvideUtilities();
    Resource *buildInfrastructure();
    Buildings *createBuilding; // Was Builder , changed to Buildings

    /**
     * @brief Adds a building to the management system.
     * @param B Pointer to the building to be added.
     */
    void addBuilding(Buildings *B);

    /**
     * @brief Removes a building from the management system.
     * @param B Pointer to the building to be removed.
     */
    void remBuilding(Buildings *B);

    /**
     * @brief Adds a citizen to the population.
     * @param C Pointer to the citizen to be added.
     */
    void addCitizen(Citizen *C);

    /**
     * @brief Removes a citizen from the population.
     * @param C Pointer to the citizen to be removed.
     */
    void remCitizen(Citizen *C);

    /**
     * @brief Adds a utility to the management system.
     * @param U Pointer to the utility to be added.
     */
    void addUtility(Utility *U);

    /**
     * @brief Removes a utility from the management system.
     * @param U Pointer to the utility to be removed.
     */
    void remUtility(Utility *U);

    /**
     * @brief Gets total Energy Supply
     * @return Calls the function of the UtilitiesManager to calculate total power in the city
     */
    int getCurrentEnergySupply();
    /**
     * @brief Gets total WasteManagment
     * @return Calls the function of the UtilitiesManager to calculate total Waste Managment in the city
     */
    int getCurrentWasteSupply();
    /**
     * @brief Gets total Water Supply
     * @return Calls the function of the UtilitiesManager to calculate total Water in the city
     */
    int getCurrentWaterSupply();
    /**
     * @brief Gets total Sewage Managment
     * @return Calls the function of the UtilitiesManager to calculate total Sewage Managment in the city
     */
    int getCurrentSewageSupply();
    /**
     * @brief Gets total Amount of Utility Buildings
     * @return Calls the function of the UtilitiesManager and Returns the total amount of Utility buildings in the city
     */
    int getAmountOfUtilities();
    /**
     * @brief Gets total Amount of Income of the City
     * @return Calls The functions to get the Tax Rate of the citizens and adds it to the income of the Commercial Buildings
     */
    double getTotalIncome(); // Through Citizen Interface I presume ? Just gonna add TaxableIncome with CommercialIncome for now
    /**
     * @brief Gets total Cost of Water for All Buildings
     * @return Calls the function of the BuildingManager and Returns the total amount of Water Demand in the city
     */
    int getBuildingWaterCost();
    /**
     * @brief Gets total Cost of Power for All Buildings
     * @return Calls the function of the BuildingManager and Returns the total amount of Power Demand in the city
     */
    int getBuildingPowerCost();
    /**
     * @brief Gets total Cost of Waste Recycling for All Buildings
     * @return Calls the function of the BuildingManager and Returns the total amount of Waste Recycling Demand in the city
     */
    int getBuildingWasteCost();
    /**
     * @brief Gets total Cost of Sewage Recycling for All Buildings
     * @return Calls the function of the BuildingManager and Returns the total amount of Sewage Recycling Demand in the city
     */
    int getBuildingSewageCost();
    /**
     * @brief Gets the list of Citizens in Homes
     * @return Calls the function of the BuildingManager and Returns a List of Citizens that reside in Residential Buildings
     */
    Citizen **getBuildingCitizenInRes();
    /**
     * @brief Gets the Amount of income of Commercial Buildings
     * @return Calls the function of the BuildingManager and The total amount of Income that all Commercial Buildings Generate
     */
    int getBuildingCommercialIncome();
    /**
     * @brief Gets the Total Population of the City
     * @return Calls the function of the CitizenManager and returns the total amount of Citizens in the city
     */
    int AmountOfCitizens();
    /**
     * @brief Gets the Total Employed Population of the City
     * @return Calls the function of the CitizenManager and returns the total amount of Employed Citizens in the city
     */
    int EmployedCitizens();
    /**
     * @brief Gets the Total Home Owners Population of the City
     * @return Calls the function of the CitizenManager and returns the total amount of Property Owners in the city
     */
    int PropertyOwners();
    /**
     * @brief Calculates Satisfaction
     * @return Calls the function of the CitizenManager that Calculates the average Satisfaction of the Citizens in the City
     */
    double AvgSatisfaction();
    /**
     * @brief Returns Taxable Income
     * @return Calls the function of the CitizenManager that Calculates Total amount of Taxable Income of the Citizens
     */
    float TaxableIncome();
    /**
     * @brief Returns The Citizens
     * @return Calls the function of the CitizenManager and Returns a List of all Citizens in the City
     */
    Citizen **getListOfCitizens();
};

#endif
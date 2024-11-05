/**
 * @file BudgetAllocationSystem.h
 * @brief Header file for the BudgetAllocationSystem class which implements the third subsystem of the Facade design pattern
 * @author Design Wits
 * @date 2024-10-30
 */

#ifndef __BudgetAllocationSystem_h__
#define __BudgetAllocationSystem_h__

/**
 * @class BudgetAllocationSystem
 * @brief Represents the budget allocation system that manages the distribution of funds for various public services and infrastructure
 *
 * The BudgetAllocationSystem class is responsible for allocating available funds to different categories of public services and infrastructure projects,
 * such as medical centers, schools, police stations, utilities, transportation, and recreational facilities.
 */
class BudgetAllocationSystem
{
public:
    /**
     * @brief Constructs a new BudgetAllocationSystem object
     */
    BudgetAllocationSystem();

    /**
     * @brief Allocates funds for medical centers
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for medical centers
     */
    double allocateMedicalCenterFunds(double availableFunds);

    /**
     * @brief Allocates funds for schools
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for schools
     */
    double allocateSchoolFunds(double availableFunds);

    /**
     * @brief Allocates funds for police stations
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for police stations
     */
    double allocatePoliceStationFunds(double availableFunds);

    /**
     * @brief Allocates funds for power plants
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for power plants
     */
    double allocatePowerPlantFunds(double availableFunds);

    /**
     * @brief Allocates funds for water towers
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for water towers
     */
    double allocateWaterTowerFunds(double availableFunds);

    /**
     * @brief Allocates funds for waste plants
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for waste plants
     */
    double allocateWastePlantFunds(double availableFunds);

    /**
     * @brief Allocates funds for sewage pipes
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for sewage pipes
     */
    double allocateSewagePipeFunds(double availableFunds);

    /**
     * @brief Allocates funds for roads
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for roads
     */
    double allocateRoadsFunds(double availableFunds);

    /**
     * @brief Allocates funds for airports
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for airports
     */
    double allocateAirportsFunds(double availableFunds);

    /**
     * @brief Allocates funds for train stations
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for train stations
     */
    double allocateTrainStationsFunds(double availableFunds);

    /**
     * @brief Allocates funds for parks
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for parks
     */
    double allocateParkFunds(double availableFunds);

    /**
     * @brief Allocates funds for monuments
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for monuments
     */
    double allocateMonumentFunds(double availableFunds);

    /**
     * @brief Allocates funds for cultural centers
     * @param availableFunds The total available funds
     * @return The amount of funds allocated for cultural centers
     */
    double allocateCulturalCenterFunds(double availableFunds);
};

#endif // __BudgetAllocationSystem_h__

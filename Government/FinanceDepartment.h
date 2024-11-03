/**
 * @file FinanceDepartment.h
 * @brief Header file for the FinanceDepartment class implementing the Facade design pattern
 * @author Design Wits
 * @date 2024-10-30
 */
#ifndef __FinanceDepartment_h__
#define __FinanceDepartment_h__
#include <exception>
#include <vector>
#include "ResidentialTaxationSystem.h"
#include "CommercialTaxationSystem.h"
#include "BudgetAllocationSystem.h"
#include "CitizenInterface.h"
#include "CommercialBuilding.h"
using namespace std;



/**
 * @class FinanceDepartment
 * @brief Represents the finance department of a government that manages taxation and budget allocation
 * 
 * The FinanceDepartment class is responsible for collecting taxes from residential and commercial entities,
 * maintaining financial records, and allocating funds for various public services and infrastructure projects.
 */
class FinanceDepartment
{
private:
    /** @brief Pointer to the residential taxation system */
    ResidentialTaxationSystem *residentialTaxation;
    /** @brief Pointer to the commercial taxation system */
    CommercialTaxationSystem *businessTaxation;
    /** @brief Pointer to the budget allocation system */
    BudgetAllocationSystem *budgetAllocation;
    /** @brief List of all residents/citizens */
    std::vector<Citizen *> residentsList; // HAD TO CHANGE THIS TO CITIZEN VARIABLE
    /** @brief List of all commercial buildings */
    std::vector<CommercialBuilding *> commercialBuildingsList;
    /** @brief Residential income tax rate */
    double incomeTaxRate;
    /** @brief Residential property tax rate */
    double propertyTaxRate;
    /** @brief Commercial business tax rate */
    double businessTaxRate;
    /** @brief Commercial sales tax rate */
    double salesTaxRate;
    /** @brief Total business sales */
    double totalBusinessSales;
    /** @brief Total business profits */
    double totalBusinessProfits;
    /** @brief Total residents' incomes */
    double totalResidentsIncomes;
    /** @brief Total available funds in the Finance Department*/
    double availableFunds;

public:
    /**
     * @brief Constructs a new FinanceDepartment object
     */
    FinanceDepartment();

    /**
     * @brief Constructs a new FinanceDepartment object with initial residents and commercial buildings
     * @param residentsList Vector of CitizenInterface pointers representing the citizens in the city
     * @param commercialBuildingsList Vector of CommercialBuilding pointers representing the commercial buildings in the city
     */
    FinanceDepartment(std::vector<CitizenInterface*> residentsList, std::vector<CommercialBuilding *> commercialBuildingsList);

    /**
     * @brief Destroys the FinanceDepartment object
     */
    ~FinanceDepartment();

    /**
     * @brief Sets the available funds for the finance department
     * @param totalRevenue The total revenue collected
     */
    void setAvailableFunds(double totalRevenue);

    /**
     * @brief Sets the residential income tax rate
     * @param incomeTaxRate The new income tax rate
     */
    void setResidentialIncomeTaxRate(double incomeTaxRate);

    /**
     * @brief Sets the residential property tax rate
     * @param propertyTaxRate The new property tax rate
     */
    void setResidentialPropertyTaxRate(double propertyTaxRate);

    /**
     * @brief Sets the commercial business tax rate
     * @param businessTaxRate The new business tax rate
     */
    void setCommercialBusinessTaxRate(double businessTaxRate);

    /**
     * @brief Sets the commercial sales tax rate
     * @param salesTaxRate The new sales tax rate
     */
    void setCommercialSalesTaxRate(double salesTaxRate);

    /**
     * @brief Gets the residential income tax rate
     * @return The current residential income tax rate
     */
    double getResidentialIncomeTaxRate();

    /**
     * @brief Gets the residential property tax rate
     * @return The current residential property tax rate
     */
    double getResidentialPropertyTaxRate();

    /**
     * @brief Gets the commercial business tax rate
     * @return The current commercial business tax rate
     */
    double getCommercialBusinessTaxRate();

    /**
     * @brief Gets the commercial sales tax rate
     * @return The current commercial sales tax rate
     */
    double getCommercialSalesTaxRate();

    /**
     * @brief Gets the available funds
     * @return The current available funds
     */
    double getAvailableFunds();

    /**
     * @brief Delegates the request for collection of property tax
     * @return The total property tax collected
     */
    double delegateRequestForCollectionOffPropertyTax();

    /**
     * @brief Delegates the request for collection of income tax
     * @return The total income tax collected
     */
    double delegateRequestForCollectionOffIncomeTax();

    /**
     * @brief Delegates the request for collection of business tax
     * @return The total business tax collected
     */
    double delegateRequestForCollectionOfBusinessTax();

    /**
     * @brief Delegates the request for collection of sales tax
     * @return The total sales tax collected
     */
    double delegateRequestForCollectionOfSalesTax();

    /**
     * @brief Delegates the request for allocation of funds for public service buildings
     * @return The amount of funds allocated
     */
    double delegateRequestForAllocationOfPublicServiceBuildingsFunds();

    /**
     * @brief Delegates the request for allocation of funds for utilities
     * @return The amount of funds allocated
     */
    double delegateRequestForAllocationOfUtilitiesFunds();

    /**
     * @brief Delegates the request for allocation of funds for transport infrastructure
     * @return The amount of funds allocated
     */
    double delegateRequestForAllocationOfTransportInfrastructureFunds();

    /**
     * @brief Delegates the request for allocation of funds for landmark buildings (synonymous with recreation)
     * @return The amount of funds allocated
     */
    double delegateRequestForAllocationOfLandmarkBuildingsFunds();

    /**
     * @brief Calculates the total residents' income
     * @return The total residents' income
     */
    double calculateTotalResidentsIncome();

    /**
     * @brief Calculates the total business profit
     * @return The total business profit
     */
    double calculateTotalBusinessProfit();

    /**
     * @brief Calculates the total business sales
     * @return The total business sales
     */
    double calculateTotalBusinessSale();

    /**
     * @brief Adds a new resident to the residents list
     * @param resident Pointer to the CitizenInterface object to be added
     * @return void
     */
    void addResidents(Citizen *resident);

    /**
     * @brief Adds a new commercial building to the commercial buildings list
     * @param commercialBuilding Pointer to the CommercialBuilding object to be added
     * @return void
     */
    void addCommercialBuilding(CommercialBuilding *commercialBuilding);
};

#endif // __FinanceDepartment_h__

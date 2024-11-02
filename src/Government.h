/**
 * @file Government.h
 * @brief Government class header implementing Observer and Chain of Responsibility patterns
 * @author Design Wits
 * @date 2024-04-29
 */

#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <memory>
#include <string>
#include "Citizen.h"
#include "Command.h"
#include "FinanceDepartment.h"


/**
 * @class Government
 * @brief Base class for government sectors implementing Observer pattern for citizen notifications
 * 
 * This class manages citizens, budget allocation, and tax collection while implementing
 * the Observer pattern to notify citizens of changes in tax rates and policies.
 */
class Government {
private:
    std::vector<CitizenInterface*> citizenList;  ///< List of citizen observers
    Government* successor;                        ///< Next handler in chain of responsibility
    Government* requestee;                        ///< Government entity handling requests
    std::vector<std::unique_ptr<Command>> commands; ///< Command pattern implementation
    double budget;                               ///< Current government budget
    double totalRevenue;                         ///< Total collected revenue
    double currentTaxRate;                        ///< Current tax rate for citizen notifications
    FinanceDepartment* financeDepartment; ///< Finance branch of the Government

public:
    /** @brief Default constructor */
    Government();

    /** @brief Parameterized  constructor */
    Government(FinanceDepartment *financeDepartment);

    /** @brief Virtual destructor */
    virtual ~Government() = default;
    
    /**
     * @brief Attaches a citizen observer to the government
     * @param citizen Pointer to citizen to attach
     */
    void attach(Citizen* citizen);
    
    /**
     * @brief Detaches a citizen observer from the government
     * @param citizen Pointer to citizen to detach
     */
    void detach(Citizen* citizen);
    
    /**
     * @brief Notifies all citizen observers of changes in tax rates
     */
    void notify();
    
    /**
     * @brief Adds a command to the command queue
     * @param command Unique pointer to command to add
     */
    void addCommand(std::unique_ptr<Command> command);
    
    /**
     * @brief Executes all commands in the queue
     */
    void executeCommands();
    
    /**
     * @brief Collects property tax
     * @return Amount of property tax collected
     */
    double requestCollectionOfPropertyTax();
    
    /**
     * @brief Collects income tax
     * @return Amount of income tax collected
     */
    double requestCollectionOfIncomeTax();
    
    /**
     * @brief Collects business tax
     * @return Amount of business tax collected
     */
    double requestCollectionOfBusinessTax();
    
    /**
     * @brief Collects sales tax
     */
    double requestCollectionOfSalesTax();
    
    /**
     * @brief Allocates funds for utilities
     * @return Amount allocated for utilities
     */
    double requestAllocationOfUtilitiesFunds();
    
    /**
     * @brief Allocates funds for PublicServiceBuildings such as HealthCare ,Education and Police Station
     * @return Amount allocated for PublicServiceBuildings such as HealthCare ,Education and Police Station
     */
    double requestAllocationOfPublicServiceBuildingsFunds();
    
    /**
     * @brief Allocates funds for transport
     * @return Amount allocated for transport
     */
    double requestAllocationOfTransportFunds();
    

    
    /**
     * @brief Allocates funds for recreation
     * @return Amount allocated for recreation
     */
    double requestAllocationOfRecreationFunds();
    
    /**
     * @brief Sets the government budget
     * @param b New budget amount
     */
    void setBudget(double b);
    
    /**
     * @brief Gets the current budget
     * @return Current budget amount
     */
    double getBudget() const;
    
     /**
     * @brief Sets the total revenue
     * @param b Current revenue amount
     */
    void setTotalRevenue(double b);
    
    /**
     * @brief Gets the total revenue
     * @return Total revenue amount
     */
    double getTotalRevenue() const;

    /**
     * @brief Handles citizen requests
     * @param requestDetails Details of the request
     */
    virtual void handleRequest(std::string requestDetails);
};

#endif // GOVERNMENT_H

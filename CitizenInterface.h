#ifndef CITIZEN_INTERFACE_H
#define CITIZEN_INTERFACE_H

#include <string>
#include <memory>
#include "Government.h"
#include "Transport.h"
#include "PopulationControl.h"

class Government;
class Transport;
class PopulationControl;

/**
 * @class CitizenInterface
 * @brief An abstract base class that defines the interface for Citizen components.
 *
 * This interface provides a common structure for all citizen-related classes, including
 * functions for tax calculation, salary adjustments, public service requests, and cloning capabilities.
 */
class CitizenInterface {
public:
    /**
     * @brief Virtual destructor to allow for polymorphic deletion.
     */
    virtual ~CitizenInterface() = default;

    /**
     * @brief Clones the citizen object.
     * @return A unique pointer to a new CitizenInterface object that is a clone of this object.
     */
    virtual std::unique_ptr<CitizenInterface> clone() = 0;

    /**
     * @brief Updates the citizen with information from a governing authority.
     * @param newTaxRate The new tax rate to be applied.
     */
    virtual void update(float newTaxRate) = 0;

    /**
     * @brief Submits a request to the government.
     * @param government The government entity to receive the request.
     * @param requestDetails The details of the request.
     */
    virtual void makeRequest(Government* government, std::string requestDetails) = 0;

    /**
     * @brief Uses transport by calling travel method in Transport hierarchy.
     * @param transport The transport system to be used.
     */
    virtual void useTransport(Transport *transport) = 0;

    /**
     * @brief Adjusts the satisfaction level of the citizen.
     * @param newSatisfaction The new satisfaction level.
     */
    virtual void adjustCitizenSatisfaction(float newSatisfaction) = 0;

    /**
     * @brief Requests access to a public service, affecting citizen satisfaction.
     * @param serviceType The type of public service requested (e.g., "Healthcare", "Education").
     * @param impact Satisfaction impact of using this service.
     */
    virtual void requestPublicService(std::string serviceType, float impact) = 0;

    /**
     * @brief Attends a city event, potentially boosting satisfaction and engagement.
     * @param eventName The name of the event.
     * @param impact The impact of the event on citizen satisfaction.
     */
    virtual void attendEvent(std::string eventName, float impact) = 0;

    /**
     * @brief Evaluates the happiness level of the citizen.
     * @return An overall happiness level considering satisfaction and other personal factors.
     */
    virtual float evaluateHappiness() = 0;
     /**
     * @brief Sets the employment status of the citizen.
     * @param employmentStatus The employment status (true for employed, false for unemployed).
     */
    virtual void setEmploymentStatus(bool employmentStatus){};

    /**
     * @brief Sets the property ownership status of the citizen.
     * @param ownsProperty The ownership status (true if owns property, false otherwise).
     */
    virtual void setPropertyOwnership(bool ownsProperty){};

    /**
     * @brief Returns the citizen's current salary.
     * @return The citizen's salary.
     */
    virtual float getSalary(){} ;

    /**
     * @brief Sets a new salary for the citizen.
     * @param newSalary The new salary amount.
     */
    virtual void setSalary(float newSalary){};
    /**
     * @brief Gets the satisfaction of the citizen.
     * @return The satisfaction of the citizen.
     */
    virtual float getSatisfaction() = 0;
    /**
     * @brief Gets the employment status of the citizen.
     * @return The employment status of the citizen.
     */
    virtual bool getEmployementStatus() = 0;
    /**
     * @brief Gets the property ownership status of the citizen.
     * @return The property ownership status of the citizen.
     */
    virtual bool getPropertyOwnershipStatus() = 0;

    /**
     * @brief Gets the age of the citizen.
     * @return The age of the citizen.
     */
    virtual int getAge(){};
    /**
     * @brief Gets the name of the citizen.
     * @return The name of the citizen.
     */
    virtual std::string getName(){};
    /**
     * @brief Displays the details of the citizen in a formatted manner.
     */
    virtual void displayDetails() = 0; // Function declaration

    virtual float getTaxRate() = 0 ; 
    virtual double getBalance() = 0 ; 
    virtual void setBalance(double newBalance) = 0 ; 

    virtual void setSatisfaction( int newSatisfaction ) = 0 ;


protected:
    std::string name;       /**< Name of the citizen. */
    float salary;           /**< Salary of the citizen. */
    float satisfaction;     /**< Satisfaction level of the citizen. */
    int age;
    bool isEmployed;        /**< Employment status of the citizen. */
    bool ownsProperty;      /**< Property ownership status of the citizen. */
    PopulationControl popControl; /**< Manages population metrics and demographics. */
    Government *government; /**< Pointer to the Government */
    float currTaxRate;
    double balance ; 
};

#endif // CITIZEN_INTERFACE_H

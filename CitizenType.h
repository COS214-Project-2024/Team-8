#ifndef CITIZENTYPE_H
#define CITIZENTYPE_H

#include "CitizenInterface.h"
#include "TravelManager.h"
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "Stops.h"

/**
 * @class CitizenType
 * @brief A decorator class for enhancing the functionality of citizen objects.
 * 
 * This class implements the CitizenInterface and wraps around a CitizenInterface 
 * instance to provide additional functionalities such as salary management, 
 * employment status, and property ownership tracking.
 */
class CitizenType : public CitizenInterface {
public:
    /**
     * @brief Constructs a CitizenType object, decorating the given citizen.
     * 
     * @param citizen The citizen instance to decorate.
     */
    CitizenType(std::unique_ptr<CitizenInterface> citizen) 
        : baseCitizen(std::move(citizen)) {}

    /**
     * @brief Clones the current CitizenType object.
     * @return A unique pointer to a new CitizenType object that is a clone of this instance.
     */
    //std::unique_ptr<CitizenInterface> clone() override {
        //return std::make_unique<CitizenType>(baseCitizen->clone());
    //}

    /**
     * @brief Updates the citizen's status based on a new tax rate.
     * 
     * Adjusts the citizen's satisfaction level according to the impact of the tax rate.
     * @param newTaxRate The new tax rate to apply.
     */
    void update(float newTaxRate) override;

    /**
     * @brief Submits a request to the government on behalf of the citizen.
     * 
     * @param government The government entity to receive the request.
     * @param requestDetails Details of the request being made.
     */
    void makeRequest(Government* government, std::string requestDetails) override;

    /**
     * @brief Utilizes a transport service for the citizen.
     * 
     * @param transport The transport system used by the citizen.
     */
    void useTransport(Stops *stop, int capacity) override;

    /**
     * @brief Adjusts the citizen's satisfaction level.
     * 
     * @param newSatisfaction New satisfaction value (0-100).
     */
    void adjustCitizenSatisfaction(float newSatisfaction) override;

    /**
     * @brief Requests a public service, impacting satisfaction.
     * 
     * @param serviceType Type of public service (e.g., "Healthcare", "Education").
     * @param impact Impact of the service on satisfaction.
     */
    void requestPublicService(std::string serviceType, float impact) override;

    /**
     * @brief Attends a public event, potentially boosting satisfaction.
     * 
     * @param eventName The name of the event.
     * @param impact The impact of the event on citizen satisfaction.
     */
    void attendEvent(std::string eventName, float impact) override;

    /**
     * @brief Evaluates the citizen's overall happiness level.
     * 
     * @return A float representing the citizen's happiness level.
     */
    float evaluateHappiness() override;

    /**
     * @brief Gets the current salary of the citizen.
     * 
     * @return The salary of the citizen.
     */
    float getSalary() override;

    /**
     * @brief Sets a new salary for the citizen.
     * 
     * @param newSalary The new salary amount.
     */
    void setSalary(float newSalary) override;

    /**
     * @brief Retrieves the citizen's current satisfaction level.
     * 
     * @return The satisfaction level (0-100).
     */
    float getSatisfaction() override;

    /**
     * @brief Gets the employment status of the citizen.
     * 
     * @return True if employed, false otherwise.
     */
    bool getEmployementStatus() override;

    /**
     * @brief Sets the employment status of the citizen.
     * 
     * @param employmentStatus True for employed, false for unemployed.
     */
    void setEmploymentStatus(bool employmentStatus) override;

    /**
     * @brief Gets the property ownership status of the citizen.
     * 
     * @return True if owns property, false otherwise.
     */
    bool getPropertyOwnershipStatus() override;

    /**
     * @brief Sets the property ownership status of the citizen.
     * 
     * @param ownsProperty True if owns property, false otherwise.
     */
    void setPropertyOwnership(bool ownsProperty) override;

    /**
     * @brief Gets the age of the citizen.
     * 
     * @return The age of the citizen.
     */
    int getAge() override;

    /**
     * @brief Retrieves the name of the citizen.
     * 
     * @return The name of the citizen.
     */
    std::string getName() override;

    /**
     * @brief Displays the details of the citizen in a formatted manner.
     */
    void displayDetails() override;
    virtual string citizenType();

    void Test() ; 
     float getTaxRate() ; 
     double getBalance() ; 
     void setBalance(double newBalance) ; 

     void setSatisfaction( int newSatisfaction ) ;
 // Delete copy constructor and copy assignment operator
    CitizenType(const CitizenType&) = delete;
    CitizenType& operator=(const CitizenType&) = delete;
     CitizenType(CitizenType&& other) noexcept 
        : baseCitizen(std::move(other.baseCitizen)), CitizenList(std::move(other.CitizenList)) {}

    CitizenType& operator=(CitizenType&& other) noexcept {
        if (this != &other) {
            baseCitizen = std::move(other.baseCitizen);
            CitizenList = std::move(other.CitizenList);
        }
        return *this;
    }


protected:
    std::unique_ptr<CitizenInterface> baseCitizen; /**< The underlying citizen object being decorated. */
    std::vector<Citizen*> CitizenList; 
};

#endif // CITIZENTYPE_H

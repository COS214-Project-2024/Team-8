#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <memory>
#include "CitizenInterface.h"

/**
 * @class Citizen
 * @brief Represents a citizen in the government system.
 *
 * This class implements the CitizenInterface and represents an individual citizen
 * who can interact with the government, access services, and attend events.
 */
class Citizen : public CitizenInterface
{
public:
        /**
         * @brief Constructs a Citizen object.
         * @param name The name of the citizen.
         * @param salary The initial salary of the citizen.
         * @param age The age of the citizen.
         * @param satisfaction The initial satisfaction level of the citizen.
         * @param government Pointer to the Government object.
         * @param hasJob Employment status of the citizen (default is false).
         * @param ownsProperty Property ownership status of the citizen (default is false).
         */
        Citizen(std::string name, float salary, int age, float satisfaction,
                Government *government, bool hasJob = false, bool ownsProperty = false);

        Citizen(std::string name, float salary, int age, float satisfaction);

        /**
         * @brief Destructor for the Citizen object.
         */
        ~Citizen() override;

        /**
         * @brief Clones the citizen object.
         * @return A unique pointer to a new CitizenInterface object that is a clone of this object.
         */
        std::unique_ptr<CitizenInterface> clone() override;

        void setBalance(int bal) ;
        int getBalance();

        void setSatisfaction(float satis);

        /**
         * @brief Updates the citizen with information from a governing authority.
         * @param newTaxRate The new tax rate to be applied.
         */
        void update(float newTaxRate) override;

        /**
         * @brief Submits a request to the government.
         * @param government Pointer to the Government object to handle the request.
         * @param requestDetails The details of the request.
         */
        void makeRequest(Government *government, std::string requestDetails) override;

        /**
         * @brief Uses transport by calling the travel method in the Transport hierarchy.
         * @param transport Pointer to a Transport object.
         */
        void useTransport(Transport *transport) override;

        /**
         * @brief Adjusts the satisfaction level of the citizen.
         * @param newSatisfaction The new satisfaction level.
         */
        void adjustCitizenSatisfaction(float newSatisfaction) override;

        /**
         * @brief Sets the employment status of the citizen.
         * @param employmentStatus The employment status (true for employed, false for unemployed).
         */
        void setEmploymentStatus(bool employmentStatus);

        /**
         * @brief Sets the property ownership status of the citizen.
         * @param ownsProperty The ownership status (true if owns property, false otherwise).
         */
        void setPropertyOwnership(bool ownsProperty);

        /**
         * @brief Returns the citizen's current salary.
         * @return The citizen's salary.
         */
        float getSalary();

        /**
         * @brief Sets a new salary for the citizen.
         * @param newSalary The new salary amount.
         */
        void setSalary(float newSalary);

        /**
         * @brief Gets the age of the citizen.
         * @return The age of the citizen.
         */
        int getAge();
        /**
         * @brief Gets the name of the citizen.
         * @return The name of the citizen.
         */
        std::string getName();
        /**
         * @brief Gets the satisfaction of the citizen.
         * @return The satisfaction of the citizen.
         */
        float getSatisfaction();

        /**
         * @brief Requests access to a public service, affecting citizen satisfaction.
         * @param serviceType The type of public service requested (e.g., "Healthcare", "Education").
         * @param impact Satisfaction impact of using this service.
         */
        void requestPublicService(std::string serviceType, float impact) override;

        /**
         * @brief Attends a city event, potentially boosting satisfaction and engagement.
         * @param eventName The name of the event.
         * @param impact The impact of the event on citizen satisfaction.
         */
        void attendEvent(std::string eventName, float impact) override;

        /**
         * @brief Evaluates the happiness level of the citizen.
         * @return An overall happiness level considering satisfaction and other personal factors.
         */
        float evaluateHappiness() override;
        /**
         * @brief Displays the details of the citizen in a formatted manner.
         */
        void displayDetails(); // Function declaration
        /**
         * @brief Gets the employment status of the citizen.
         * @return The employment status of the citizen.
         */
        bool getEmployementStatus();
        /**
         * @brief Gets the property ownership status of the citizen.
         * @return The property ownership status of the citizen.
         */
        bool getPropertyOwnershipStatus();

protected:
        std::string name;             /**< Name of the citizen. */
        float salary;                 /**< Salary of the citizen. */
        float satisfaction;           /**< Satisfaction level of the citizen. */
        int age;                      /**< Age of the citizen. */
        bool isEmployed;              /**< Employment status of the citizen. */
        bool ownsProperty;            /**< Property ownership status of the citizen. */
        PopulationControl popControl; /**< Manages population metrics and demographics. */
        Government *government;       /**< Pointer to the Government */
        float currTaxRate;            /**< Current tax rate for the citizen. */
};

#endif // CITIZEN_H

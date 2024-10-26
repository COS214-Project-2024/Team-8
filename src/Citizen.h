#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <memory>
#include "CitizenInterface.h"

// Forward declaration of the Government class
class Government;

/**
 * @class Citizen
 * @brief Represents a citizen in the government system.
 *
 * This class implements the CitizenInterface and represents an individual citizen 
 * who can interact with the government and has properties like salary and satisfaction.
 */
class Citizen : public CitizenInterface {
public:
    /**
     * @brief Constructs a Citizen object.
     * 
     * @param name The name of the citizen.
     * @param salary The initial salary of the citizen.
     * @param government Pointer to the Government object.
     * @param hasJob Employment status of the citizen (default is false).
     * @param ownsProperty Property ownership status of the citizen (default is false).
     */
    Citizen(const std::string& name, float salary, Government* government, bool hasJob = false, bool ownsProperty = false);
    
    /**
     * @brief Destructor for the Citizen object.
     */
    ~Citizen() override;

    /**
     * @brief Calculates tax based on the citizen's salary and property ownership.
     * @return Calculated tax amount.
     */
    float calculateTax() override;

    /**
     * @brief Applies tax to the citizen's salary.
     */
    void applyTax() override;

    /**
     * @brief Increases the citizen's salary by a given percentage.
     * @param percentage The percentage increase.
     */
    void jobPromotion(float percentage) override;

    /**
     * @brief Clones the citizen object.
     * @return A unique pointer to a new CitizenInterface object that is a clone of this object.
     */
    std::unique_ptr<CitizenInterface> clone() override;

    /**
     * @brief Updates the citizen with information from a governing authority.
     * @param newTaxRate The new tax rate to be applied.
     */
    void update(float newTaxRate) override;

    /**
     * @brief Submits a request to the government.
     * 
     * @param government Pointer to the Government object to handle the request.
     * @param requestDetails The details of the request.
     */
    void makeRequest(Government* government, std::string& requestDetails) override;
    void useTransport(Transport *transport);

private:
    Government* government; /**< Pointer to the Government */
    bool hasJob;            /**< Employment status of the citizen */
    bool ownsProperty;      /**< Property ownership status of the citizen */
};

#endif // CITIZEN_H

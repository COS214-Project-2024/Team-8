#ifndef CITIZEN_TYPE_H
#define CITIZEN_TYPE_H

#include "CitizenInterface.h"

/**
 * @class CitizenType
 * @brief Abstract decorator class for citizen types.
 *
 * This class serves as a base for specific citizen decorators, 
 * allowing additional functionality to be added to citizen objects.
 */
class CitizenType : public CitizenInterface {
public:
    /**
     * @brief Constructs a CitizenType object.
     * 
     * @param baseCitizen A unique pointer to the base citizen.
     */
    CitizenType(std::unique_ptr<CitizenInterface> baseCitizen);

    /**
     * @brief Calculates tax based on the citizen's properties.
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

protected:
    std::unique_ptr<CitizenInterface> baseCitizen; /**< Pointer to the base citizen */
};

#endif // CITIZEN_TYPE_H

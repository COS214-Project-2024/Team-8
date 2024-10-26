#ifndef RESIDENTIAL_CITIZEN_H
#define RESIDENTIAL_CITIZEN_H

#include "CitizenType.h"
#include "Buildings.h"
#include <memory>

/**
 * @class ResidentialCitizen
 * @brief Concrete decorator class for citizens with residential property.
 *
 * Enhances the base Citizen functionality with specific attributes and behaviors
 * related to residential property ownership and residence management.
 */
class ResidentialCitizen : public CitizenType {
public:
    /**
     * @brief Constructs a ResidentialCitizen object.
     * 
     * @param baseCitizen A unique pointer to the base citizen object.
     */
    ResidentialCitizen(std::unique_ptr<CitizenInterface> baseCitizen);

    /**
     * @brief Allows the citizen to move into a residence.
     *
     * Adjusts the citizen’s status to indicate residence and boosts satisfaction.
     *
     * @param building A pointer to the building the citizen is moving into.
     */
    void moveIntoResidence(Buildings* building);

    /**
     * @brief Calculates the tax for the citizen based on salary and property ownership.
     * 
     * @return The calculated tax amount.
     */
    float calculateTax() override;

    /**
     * @brief Applies the calculated tax to the citizen's salary.
     */
    void applyTax() override;

    /**
     * @brief Enhances citizen's satisfaction level through residence upgrade.
     * 
     * @param satisfactionBoost The amount by which to increase satisfaction.
     */
    void upgradeResidence(float satisfactionBoost);

private:
    bool hasResidence;      /**< Indicates whether the citizen has a residence. */
    bool ownsProperty;      /**< Indicates whether the citizen owns residential property. */
    float currTaxRate;      /**< Stores the current tax rate applied to the citizen's income. */
};

#endif // RESIDENTIAL_CITIZEN_H

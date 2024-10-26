#ifndef POLITICAL_CITIZEN_H
#define POLITICAL_CITIZEN_H

#include "CitizenType.h"
#include "Government.h"
#include <memory>

/**
 * @class PoliticalCitizen
 * @brief Concrete decorator class for citizens with political involvement.
 *
 * Enhances the base Citizen functionality by adding attributes and behaviors
 * related to political engagement and influence.
 */
class PoliticalCitizen : public CitizenType {
public:
    /**
     * @brief Constructs a PoliticalCitizen object.
     * 
     * @param baseCitizen A unique pointer to the base citizen object.
     */
    PoliticalCitizen(std::unique_ptr<CitizenInterface> baseCitizen);

    /**
     * @brief Allows the citizen to actively engage in political requests.
     *
     * This function enables the citizen to make policy-related requests to the government.
     *
     * @param government A pointer to the government the citizen is addressing.
     * @param requestDetails Details about the citizen's request.
     */
    void makePoliticalRequest(Government* government, const std::string& requestDetails);

    /**
     * @brief Calculates tax based on the citizen's salary and political contributions.
     * 
     * @return The calculated tax amount.
     */
    float calculateTax() override;

    /**
     * @brief Applies the calculated tax to the citizen's salary.
     */
    void applyTax() override;

    /**
     * @brief Boosts the citizen's influence level to reflect political promotions.
     * 
     * @param influenceBoost The amount by which to increase political influence.
     */
    void promotePoliticalInfluence(float influenceBoost);

private:
    bool politicallyActive; /**< Indicates if the citizen is actively involved in politics. */
    float currTaxRate;      /**< Stores the current tax rate applied to the citizen's income. */
    float influenceLevel;   /**< Represents the citizen's level of political influence. */
};

#endif // POLITICAL_CITIZEN_H

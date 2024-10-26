#ifndef EMPLOYED_CITIZEN_H
#define EMPLOYED_CITIZEN_H

#include "CitizenType.h"
#include "Buildings.h"
#include <memory>

/**
 * @class EmployedCitizen
 * @brief Concrete decorator class for employed citizens.
 *
 * This class adds specific attributes and behaviors related to employed citizens,
 * enhancing the base Citizen functionality.
 */
class EmployedCitizen : public CitizenType {
public:
    /**
     * @brief Constructs an EmployedCitizen object.
     * 
     * @param baseCitizen A unique pointer to the base citizen.
     */
    EmployedCitizen(std::unique_ptr<CitizenInterface> baseCitizen);

    /**
     * @brief Sets employment for the citizen at a specified building.
     * Adjusts the salary and updates satisfaction based on employment status.
     * 
     * @param building Pointer to the building offering employment.
     */
    void getEmployed(Buildings* building) ;

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

private:
    Government* government; /**< Pointer to the Government */
    bool hasJob = false;    /**< Employment status of the citizen */
    bool ownsProperty = false; /**< Property ownership status of the citizen */
    float currTaxRate = 0.0f; /**< Current tax rate applied to the citizen */
};

#endif // EMPLOYED_CITIZEN_H

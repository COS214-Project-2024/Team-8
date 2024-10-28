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
    void getEmployed(Buildings* building);

    /**
     * @brief Increases the citizen's salary by a given percentage.
     * 
     * @param percentage The percentage increase.
     */
    void jobPromotion(float percentage);

    /**
     * @brief Returns the type of the citizen.
     * @return A string representing the type of the citizen.
     */
    std::string citizenType()  override;
};

#endif // EMPLOYED_CITIZEN_H

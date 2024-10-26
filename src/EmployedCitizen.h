#ifndef EMPLOYED_CITIZEN_H
#define EMPLOYED_CITIZEN_H

#include "CitizenType.h"

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

};

#endif // EMPLOYED_CITIZEN_H

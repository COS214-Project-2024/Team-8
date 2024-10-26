#ifndef RESIDENTIAL_CITIZEN_H
#define RESIDENTIAL_CITIZEN_H

#include "CitizenType.h"

/**
 * @class ResidentialCitizen
 * @brief Concrete decorator class for residential citizens.
 *
 * This class adds specific attributes and behaviors related to residential citizens,
 * enhancing the base Citizen functionality.
 */
class ResidentialCitizen : public CitizenType {
public:
    /**
     * @brief Constructs a ResidentialCitizen object.
     * 
     * @param baseCitizen A unique pointer to the base citizen.
     */
    ResidentialCitizen(std::unique_ptr<CitizenInterface> baseCitizen);

};

#endif // RESIDENTIAL_CITIZEN_H

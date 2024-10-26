#ifndef POLITICAL_CITIZEN_H
#define POLITICAL_CITIZEN_H

#include "CitizenType.h"

/**
 * @class PoliticalCitizen
 * @brief Concrete decorator class for politically active citizens.
 *
 * This class adds specific attributes and behaviors related to politically active citizens,
 * enhancing the base Citizen functionality.
 */
class PoliticalCitizen : public CitizenType {
public:
    /**
     * @brief Constructs a PoliticalCitizen object.
     * 
     * @param baseCitizen A unique pointer to the base citizen.
     */
    PoliticalCitizen(std::unique_ptr<CitizenInterface> baseCitizen);
};

#endif // POLITICAL_CITIZEN_H

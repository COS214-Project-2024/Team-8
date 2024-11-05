#ifndef RESIDENTIAL_CITIZEN_H
#define RESIDENTIAL_CITIZEN_H

#include "CitizenType.h"
#include "Buildings.h"
#include <memory>

/**
 * @class PropertyOwner
 * @brief Concrete decorator class for citizens with residential property.
 *
 * Enhances the base Citizen functionality with specific attributes and behaviors
 * related to residential property ownership and residence management.
 */
class PropertyOwner : public CitizenType {
public:
    /**
     * @brief Constructs a PropertyOwner object.
     * 
     * @param baseCitizen A unique pointer to the base citizen object.
     */
    PropertyOwner(std::unique_ptr<CitizenInterface> baseCitizen);

    /**
     * @brief Allows the citizen to move into a residence.
     *
     * Adjusts the citizen’s status to indicate residence and boosts satisfaction.
     *
     * @param building A pointer to the building the citizen is moving into.
     */
    void moveIntoResidence(Buildings* building);

    /**
     * @brief Enhances citizen's satisfaction level through residence upgrade.
     * 
     * @param satisfactionBoost The amount by which to increase satisfaction.
     */
    void upgradeResidence(float satisfactionBoost);
    std::string citizenType();
};

#endif // RESIDENTIAL_CITIZEN_H

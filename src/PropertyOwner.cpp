#include "PropertyOwner.h"
#include "Buildings.h"
#include <memory>

PropertyOwner::PropertyOwner(std::unique_ptr<CitizenInterface> baseCitizen)
    : CitizenType(std::move(baseCitizen)) {}

void PropertyOwner::moveIntoResidence(Buildings* building) {
    if (building != nullptr) {
        // Set property ownership and adjust satisfaction
        baseCitizen->setPropertyOwnership(true);
        baseCitizen->adjustCitizenSatisfaction(15.0f);

        // Output statement to indicate successful movement
        std::cout << "Congratulations! " << baseCitizen->getName() << " has successfully moved into their new residence at " 
                  << building->getName()<< std::endl;
    } else {
        // Output statement in case the building is null
        std::cout << "Unable to move into a residence: The specified building does not exist." << std::endl;
    }
}

void PropertyOwner::upgradeResidence(float satisfactionBoost) {
    // Adjust satisfaction based on the boost
    baseCitizen->adjustCitizenSatisfaction(satisfactionBoost);

    // Output statement to indicate residence upgrade
    std::cout << "Great news! " << baseCitizen->getName() << " has upgraded their residence, boosting their satisfaction by "
              << satisfactionBoost << " points. They are now enjoying an even more comfortable living space!"
              << std::endl;
}

std::string PropertyOwner::citizenType() {
    // Output statement to indicate the citizen type
    std::cout << baseCitizen->getName() << " is classified as a Property Owner, enjoying the benefits of homeownership." << std::endl;
    return "Property Owner";
}

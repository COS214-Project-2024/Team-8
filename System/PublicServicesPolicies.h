/**
 * @file PublicServicesPolicies.h
 * @brief Public services policy implementation class
 * @author Design Wits
 * @date 2024-04-29
 */

#ifndef PUBLICSERVICESPOLICIES_H
#define PUBLICSERVICESPOLICIES_H

#include "Policies.h"
#include "Citizen.h"
#include "EconomicPolicies.h"

class Citizen;
class EconomicPolicies;

/**
 * @class PublicServicesPolicies
 * @brief Concrete implementation of public services policies
 * 
 * This class handles the execution of policies related to public
 * services. It acts as a ConcreteCommand in the Command pattern
 * hierarchy and coordinates with economic policies.
 */
class PublicServicesPolicies : public Policies {
public:
    Citizen* citizen;                    ///< Affected citizen
    EconomicPolicies* economicPolicies;  ///< Related economic policies

    /**
     * @brief Construct a new Public Services Policies object
     * @param govt Pointer to the government executing the policies
     */
    explicit PublicServicesPolicies(Government* govt) : Policies(govt) {}

    /**
     * @brief Implementation of policy execution for public services
     * 
     * Defines the specific behavior for executing public services policies.
     */
    void executePolicy() override;
};

#endif // PUBLICSERVICESPOLICIES_H
/**
 * @file EconomicPolicies.h
 * @brief Economic policy implementation class
 * @author Design Wits
 * @date 2024-04-29
 */

#ifndef ECONOMICPOLICIES_H
#define ECONOMICPOLICIES_H

#include "Policies.h"
#include "PublicServicesPolicies.h"
#include "Citizen.h"

class PublicServicesPolicies;
class Citizen;

/**
 * @class EconomicPolicies
 * @brief Concrete implementation of economic policies
 * 
 * This class handles the execution of economic policies affecting
 * citizens and public services. It acts as a ConcreteCommand in
 * the Command pattern hierarchy.
 */
class EconomicPolicies : public Policies {
public:
    /**
     * @brief Construct a new Economic Policies object
     * @param govt Pointer to the government executing the policies
     */
    explicit EconomicPolicies(Government* govt);

    PublicServicesPolicies* psPolicies;  ///< Related public services policies
    Citizen* citizen;                    ///< Affected citizen

    /**
     * @brief Implementation of policy execution for economic policies
     * 
     * Defines the specific behavior for executing economic policies.
     */
    void executePolicy() override;
};

#endif // ECONOMICPOLICIES_H
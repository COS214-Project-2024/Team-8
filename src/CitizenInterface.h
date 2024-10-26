#ifndef CITIZEN_INTERFACE_H
#define CITIZEN_INTERFACE_H

#include <string>
#include <memory>
#include "Government.h"
#include "Transport.h"
#include "PopulationControl.h"
class Government;
class Transport;
class PopulationControl;

/**
 * @class CitizenInterface
 * @brief An abstract base class that defines the interface for Citizen components.
 *
 * This interface provides a common structure for all citizen-related classes, including
 * functions for tax calculation, salary adjustments, and cloning capabilities.
 */
class CitizenInterface {
public:
    /**
     * @brief Virtual destructor to allow for polymorphic deletion.
     */
    virtual ~CitizenInterface(){};

    /**
     * @brief Calculates tax based on citizen's properties.
     * @return Calculated tax amount.
     */
    virtual float calculateTax()  = 0;

    /**
     * @brief Applies tax to the citizen's salary.
     */
    virtual void applyTax() = 0;

    /**
     * @brief Increases the citizen's salary by a given percentage.
     * @param percentage The percentage increase.
     */
    virtual void jobPromotion(float percentage) = 0;

    /**
     * @brief Clones the citizen object.
     * @return A unique pointer to a new CitizenInterface object that is a clone of this object.
     */
    virtual std::unique_ptr<CitizenInterface> clone()  = 0;

    /**
     * @brief Updates the citizen with information from a governing authority.
     * @param newTaxRate The new tax rate to be applied.
     */
    virtual void update(float newTaxRate) = 0;
    /**
     * @brief Submits a request to the government.
     * 
     * @param requestDetails The details of the request.
     */
    virtual void makeRequest(Government* government, std::string& requestDetails) = 0;
    /**
     * @brief Uses transport by calling travel method in Transport hierarchy
     * 
     */
    virtual void useTransport(Transport *transport) = 0;

protected:
    std::string name;       /**< Name of the citizen. */
    float salary;           /**< Salary of the citizen. */
    float satisfaction;     /**< Satisfaction level of the citizen. */
};

#endif // CITIZEN_INTERFACE_H

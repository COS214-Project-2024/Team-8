/**
 * @file ResidentialTaxationSystem.h
 * @brief Header file for the ResidentialTaxationSystem class which implements the first subsystem of the Facade design pattern
 * @author [Your Name]
 * @date [Current Date]
 */

#ifndef __ResidentialTaxationSystem_h__
#define __ResidentialTaxationSystem_h__

using namespace std;

/**
 * @class ResidentialTaxationSystem
 * @brief Represents the residential taxation system that collects income and property taxes from residents
 *
 * The ResidentialTaxationSystem class is responsible for calculating and collecting income tax and property tax from the residential population.
 */
class ResidentialTaxationSystem
{
public:
    /**
     * @brief Constructs a new ResidentialTaxationSystem object
     */
    ResidentialTaxationSystem() {}

    /**
     * @brief Collects income tax from residents
     * @param incomeTaxRate The current income tax rate
     * @param residentsIncome The total income of the residents
     * @return The total income tax collected
     */
    double collectIncomeTax(double incomeTaxRate, double residentsIncome);

    /**
     * @brief Collects property tax from residents
     * @param propertyTaxRate The current property tax rate
     * @param residentsIncome The total income of the residents
     * @return The total property tax collected
     */
    double collectPropertyTax(double propertyTaxRate, double residentsIncome);
};

#endif // __ResidentialTaxationSystem_h__

/**
 * @file CommercialTaxationSystem.h
 * @brief Header file for the CommercialTaxationSystem class which implements the second subsystem of the Facade design pattern
 * @author Design Wits
 * @date 2024-10-30
 */

#ifndef __CommercialTaxationSystem_h__
#define __CommercialTaxationSystem_h__

using namespace std;

/**
 * @class CommercialTaxationSystem
 * @brief Represents the commercial taxation system that collects business tax and sales tax from commercial entities
 *
 * The CommercialTaxationSystem class is responsible for calculating and collecting business tax and sales tax from commercial businesses.
 */
class CommercialTaxationSystem
{
public:
    /**
     * @brief Constructs a new CommercialTaxationSystem object
     */
    CommercialTaxationSystem();

    /**
     * @brief Collects business tax from commercial entities
     * @param businessTaxRate The current business tax rate
     * @param businessProfit The total profit of the commercial businesses
     * @return The total business tax collected
     */
    double collectBusinessTax(double businessTaxRate, double businessProfit);

    /**
     * @brief Collects sales tax from commercial entities
     * @param salesTaxRate The current sales tax rate
     * @param businessProfit The total profit of the commercial businesses
     * @return The total sales tax collected
     */
    double collectSalesTax(double salesTaxRate, double businessProfit);
};

#endif // __CommercialTaxationSystem_h__
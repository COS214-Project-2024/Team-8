/**
 * @file FinanceSector.h
 * @brief Finance Sector class header
 * @author Design Wits
 * @date 2024-04-29
 */
#ifndef FinanceSector_h
#define FinanceSector_h

#include <exception>
#include "Government.h"

using namespace std;

/**
 * @class FinanceSector
 * @brief Handles finance-related aspects of government operations
 *
 * This class specializes the Government class to handle finance-specific
 * requests and operations.
 */
class FinanceSector : public Government {
public:
    /**
     * @brief Constructor for FinanceSector
     * @param financeDepartment Pointer to the finance department
     */
    FinanceSector(FinanceDepartment *financeDepartment) : Government(financeDepartment) {};

    /**
     * @brief Handles finance-specific requests
     * @param requestDetails Details of the finance request
     */
    void handleRequest(std::string requestDetails) override;
};

#endif
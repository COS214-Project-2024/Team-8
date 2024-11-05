/**
 * @file UtilitiesSector.h
 * @brief Utilities Sector class header
 * @author Design Wits
 * @date 2024-04-29
 */
#ifndef UtilitiesSector_h
#define UtilitiesSector_h

#include <exception>
#include "Government.h"

using namespace std;

/**
 * @class UtilitiesSector
 * @brief Handles utility-related aspects of government operations
 *
 * This class specializes the Government class to handle utility-specific
 * requests and operations.
 */
class UtilitiesSector : public Government {
public:
    /**
     * @brief Constructor for UtilitiesSector
     * @param financeDepartment Pointer to the finance department
     */
    UtilitiesSector(FinanceDepartment *financeDepartment) : Government(financeDepartment) {};

    /**
     * @brief Handles utility-specific requests
     * @param requestDetails Details of the utilities request
     */
    void handleRequest(std::string requestDetails) override;
};

#endif
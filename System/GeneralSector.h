/**
 * @file GeneralSector.h
 * @brief General Sector class header
 * @author Design Wits
 * @date 2024-04-29
 */
#ifndef GeneralSector_h
#define GeneralSector_h

#include <exception>
#include "Government.h"

using namespace std;

/**
 * @class GeneralSector
 * @brief Handles general aspects of government operations
 *
 * This class specializes the Government class to handle general
 * requests and operations.
 */
class GeneralSector : public Government {
public:
    /**
     * @brief Constructor for GeneralSector
     * @param financeDepartment Pointer to the finance department
     */
    GeneralSector(FinanceDepartment *financeDepartment) : Government(financeDepartment) {};

    /**
     * @brief Handles general requests
     * @param requestDetails Details of the general request
     */
    void handleRequest(std::string requestDetails) override;
};

#endif
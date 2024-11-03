/**
 * @file FinanceSection.h
 * @brief Finance Section class header
 * @author Design Wits
 * @date 2024-04-29
 */

#ifndef FinanceSection_h
#define FinanceSection_h

#include <exception>
#include "Government.h"

using namespace std;

/**
 * @class FinanceSection
 * @brief Handles financial aspects of government operations
 * 
 * This class specializes the Government class to handle finance-specific
 * requests and operations.
 */
class FinanceSection : public Government {
public:
    /**
     * @brief Handles finance-specific requests
     * @param requestDetails Details of the finance request
     */
    void handleRequest(std::string requestDetails) override;
};

#endif
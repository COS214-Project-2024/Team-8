#include <exception>
using namespace std;

#ifndef FinanceSection_h
#define FinanceSection_h

#include "Government.h"

// class Government;

class FinanceSection : public Government {
public:
    void handleRequest(std::string requestDetails) override;
};

#endif

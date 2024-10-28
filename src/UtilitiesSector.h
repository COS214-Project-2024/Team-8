#include <exception>
using namespace std;

#ifndef UtilitiesSector_h
#define UtilitiesSector_h

// #include "Main.h"
#include "Government.h"

class UtilitiesSector : public Government {
public:
    void handleRequest(std::string requestDetails) override;
};

#endif

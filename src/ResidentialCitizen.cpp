#include "ResidentialCitizen.h"

ResidentialCitizen::ResidentialCitizen(std::unique_ptr<CitizenInterface> baseCitizen)
    : CitizenType(std::move(baseCitizen)) {
}

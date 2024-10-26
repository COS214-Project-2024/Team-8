#include "PoliticalCitizen.h"

PoliticalCitizen::PoliticalCitizen(std::unique_ptr<CitizenInterface> baseCitizen)
    : CitizenType(std::move(baseCitizen)) {
}


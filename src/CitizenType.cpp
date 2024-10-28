#include "CitizenType.h"

CitizenType::CitizenType(std::unique_ptr<CitizenInterface> citizen)
    : baseCitizen(std::move(citizen)) {}

std::unique_ptr<CitizenInterface> CitizenType::clone() {
    return std::make_unique<CitizenType>(*this);
}

void CitizenType::displayDetails()  {
    // Call the base class's displayDetails
    baseCitizen->displayDetails();

    // Additional behavior or information
    std::cout << "Citizen Type: " << citizenType() << std::endl;
}

std::string CitizenType::citizenType()  {
    return "Decorated Citizen Type";  
}

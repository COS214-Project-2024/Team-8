// Government.h
#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <memory>
#include <string>
#include "Citizen.h" // Added explicit include for Citizen class
#include "Command.h" // Added explicit include for Command class

class Government {
private:
    std::vector<Citizen*> citizenList;
    Government* successor;
    Government* requestee;
    std::vector<std::unique_ptr<Command>> commands;
    double budget;
    double totalRevenue;

public:
    Government();
    virtual ~Government() = default;  // Added virtual destructor
    
    void attach(Citizen* citizen);
    void detach(Citizen* citizen);
    void notify();
    
    void addCommand(std::unique_ptr<Command> command);
    void executeCommands();
    
    double requestCollectionOfPropertyTax();
    double requestCollectionOfIncomeTax();
    double requestCollectionOfBusinessTax();
    void requestCollectionOfSalesTax();
    
    float requestAllocationOfUtilitiesFunds();
    float requestAllocationOfHealthcareFunds();
    float requestAllocationOfTransportFunds();
    float requestAllocationOfEducationFunds();
    float requestAllocationOfRecreationFunds();
    
    void setBudget(double b);
    double getBudget() const;
    double getTotalRevenue() const;
};

#endif // GOVERNMENT_H
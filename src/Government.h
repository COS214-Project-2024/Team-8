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
    float currentTaxRate; // Added for notify() [Integrating w Tebogo]

public:
    Government();
    virtual ~Government() = default;  // Added virtual destructor
    
    void attach(Citizen* citizen);
    void detach(Citizen* citizen);
    void notify();
 //   void notifyTaxChange(float newTaxRate);  // Added specific tax notification (not too sure shame.)

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

    virtual void handleRequest(std::string requestDetails);
};

#endif // GOVERNMENT_H
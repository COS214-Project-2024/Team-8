// Government.cpp
#include "Government.h"
#include <algorithm>

Government::Government()
    : successor(nullptr), requestee(nullptr), budget(0.0), totalRevenue(0.0) {}

void Government::attach(Citizen* citizen) {
    citizenList.push_back(citizen);
}

void Government::detach(Citizen* citizen) {
    auto it = std::find(citizenList.begin(), citizenList.end(), citizen);
    if (it != citizenList.end()) {
        citizenList.erase(it);
    }
}

void Government::notify() {
    for (auto citizen : citizenList) {
        citizen->setSatisfaction(citizen->getSatisfaction() + 5.0);
      //  citizen->update(newTaxRate);
    }
}

void Government::addCommand(std::unique_ptr<Command> command) {
    commands.push_back(std::move(command));
}

void Government::executeCommands() {
    for (const auto& command : commands) {
        command->execute();
    }
    commands.clear();
}

double Government::requestCollectionOfPropertyTax() {
    double collected = 0.0;
    for (auto citizen : citizenList) {
        collected += citizen->getSalary() * 0.1; // 10% property tax
        citizen->setSatisfaction(citizen->getSatisfaction() - 2.0);
    }
    totalRevenue += collected;
    notify();
    return collected;
}

double Government::requestCollectionOfIncomeTax() {
    double collected = 0.0;
    for (auto citizen : citizenList) {
        collected += citizen->calculateTax();
        citizen->setSatisfaction(citizen->getSatisfaction() - 3.0);
    }
    totalRevenue += collected;
    notify();
    return collected;
}

double Government::requestCollectionOfBusinessTax() {
    double collected = 0.0;
    for (auto citizen : citizenList) {
        collected += citizen->getSalary() * 0.15; // 15% business tax
        citizen->setSatisfaction(citizen->getSatisfaction() - 2.5);
    }
    totalRevenue += collected;
    notify();
    return collected;
}

void Government::requestCollectionOfSalesTax() {
    double collected = 0.0;
    for (auto citizen : citizenList) {
        collected += citizen->getSalary() * 0.05; // 5% sales tax
        citizen->setSatisfaction(citizen->getSatisfaction() - 1.0);
        notify();
    }
    totalRevenue += collected;
}

float Government::requestAllocationOfUtilitiesFunds() {
    float amount = budget * 0.15f; // 15% of budget
    budget -= amount;
    notify();
    return amount;
}

float Government::requestAllocationOfHealthcareFunds() {
    float amount = budget * 0.25f; // 25% of budget
    budget -= amount;
    notify();
    return amount;
}

float Government::requestAllocationOfTransportFunds() {
    float amount = budget * 0.20f; // 20% of budget
    budget -= amount;
    notify();
    return amount;
}

float Government::requestAllocationOfEducationFunds() {
    float amount = budget * 0.30f; // 30% of budget
    budget -= amount;
    notify();
    return amount;
}

float Government::requestAllocationOfRecreationFunds() {
    float amount = budget * 0.10f; // 10% of budget
    budget -= amount;
    notify();
    return amount;
}

void Government::setBudget(double b) { budget = b; }
double Government::getBudget() const { return budget; }
double Government::getTotalRevenue() const { return totalRevenue; }
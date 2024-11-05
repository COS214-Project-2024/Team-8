/**
 * @file MallFactory.cpp
 * @brief Implementation of the MallFactory class
 */

#include "MallFactory.h"

MallFactory::MallFactory() {
    // Initialize any necessary members
}

MallFactory::~MallFactory() {
    // Cleanup if needed
}

Buildings* MallFactory::createBuilding() {
    // Create and return a new Mall object with default parameters
    return new Mall("New Mall", 500, 200, 10000.0, 300, 100, 5000.0f, 2500.0f, 100);
}
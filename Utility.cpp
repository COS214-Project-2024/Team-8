#include "Utility.h"

/**
 * @brief return the output of the Utility
 * 
 * @return float The output of the Utility
 */
float Utility::getOutput() {
    return this->Output;
}

/**
 * @brief Set the output of the Utility
 * 
 * @param Output The output of the Utility
 */
void Utility::setOutput(float Output) {
    this->Output = Output;
}

/**
 * @brief Pauses the operation of the Utility
 */
void Utility::pauseOperation() {
    std::cout << "Utility is being paused..." << std::endl;
    this->status = "Paused";
    this->commandHistory.push_back("Paused");
}

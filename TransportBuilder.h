#ifndef TRANSPORTBUILDER_H
#define TRANSPORTBUILDER_H

#include "Transport.h"
/**
 * @file TransportBuilder.h
 * 
 * @brief This file declares the TransportBuilder class interface
 */
class TransportBuilder {
protected:
	Transport* transport;

public:
	virtual TransportBuilder* setCapacity(int capacity) = 0;

	virtual Transport* build() = 0;

	virtual TransportBuilder* setCargoWeight(float weight) = 0;

	virtual TransportBuilder* setNumPassengers(int num) = 0;

	virtual ~TransportBuilder();
};

#endif

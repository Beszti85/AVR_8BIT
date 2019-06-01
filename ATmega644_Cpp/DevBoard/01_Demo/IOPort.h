/*
 * IOPort.h
 *
 * Created: 2019.05.24. 7:24:10
 *  Author: drcsabesz
 */ 


#ifndef IOPORT_H_
#define IOPORT_H_

#include "my_typedef.h"

enum PinDirection
{
	DirectionInput = 0,
	DirectionOutput = 1
};

class IOPort
{
protected:
	volatile register8_t* _port;
	volatile register8_t* _pins;
	volatile register8_t* _ddr;
public:
	IOPort(register8_t* portRegister, register8_t* pinsRegister, register8_t* ddrRegister) :
	_port(portRegister),
	_pins(pinsRegister),
	_ddr(ddrRegister) {}
	
	void SetPortDirection(register8_t directionBits);
	void SetPortValues(register8_t valueBits);
	void GetPortValues(register8_t &valueBits);

	void SetPinDirection(int pin, PinDirection direction);
	void SetPinValue(int pin, bool value);
	int GetPinValue(int pin);
    void TogglePin(int pin);
};


#endif /* IOPORT_H_ */
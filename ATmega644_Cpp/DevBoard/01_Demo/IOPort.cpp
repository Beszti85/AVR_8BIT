/*
 * IOPort.cpp
 *
 * Created: 2019.05.24. 7:24:29
 *  Author: drcsabesz
 */ 

#include "IOPort.h"

void IOPort::SetPortDirection(register8_t directionBits)
{
	*_ddr = directionBits;
}
void IOPort::SetPortValues(register8_t valueBits)
{
	*_port = valueBits;
}
void IOPort::GetPortValues(register8_t &valueBits)
{
	valueBits = *_pins;
}

void IOPort::SetPinDirection(int pin, PinDirection direction)
{
	// assumes pin is correctly in the range of 0..7
	if (direction == DirectionOutput)
	*_ddr |= (1 << pin);
	else
	*_ddr &= ~(1 << pin);
}


void IOPort::SetPinValue(int pin, bool value)
{
	// assumes pin is correctly in the range of 0..7
	
	// if the pin was already high and we want it high, do nothing.
	// if the pin was already low and we want it low, do nothing.
	// if the pin was high, and we're requesting low, toggle it
	// if the pin was low, and we're requesting high, toggle it
	
	
	if (value)
	{
		*_port |= (1 << pin);	// toggle pin because we want it low
	}
	else
	{		
		*_port &= ~(1 << pin);	// toggle pin because we want it high
	}	
}

int IOPort::GetPinValue(int pin)
{
	return (* _pins & (1 << pin));
}

void IOPort::TogglePin(int pin)
{
    *_port = ~(* _pins & (1 << pin));
}
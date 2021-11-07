/*
 * max7219.cpp
 *
 * Created: 2021. 11. 06. 14:13:03
 *  Author: drCsabesz
 */ 

#include "max7219.h"

void Max7219Driver::DisplayOnOff(bool value)
{
	ptrSpiCs->SetPinValue(pinCS, false);
	ptrSpiHw->Transmit(0x0Cu);
	ptrSpiHw->Transmit(value);
	ptrSpiCs->SetPinValue(pinCS, true);
}

void Max7219Driver::ScanLimit(uint8_t value)
{
	ptrSpiCs->SetPinValue(pinCS, false);
	ptrSpiHw->Transmit(0x0Bu);
	ptrSpiHw->Transmit(value);
	ptrSpiCs->SetPinValue(pinCS, true);
}

void Max7219Driver::DisplayTest(bool value)
{
	ptrSpiCs->SetPinValue(pinCS, false);
	ptrSpiHw->Transmit(0x0Fu);
	ptrSpiHw->Transmit(value);
	ptrSpiCs->SetPinValue(pinCS, true);
}

void Max7219Driver::SetIntensity(uint8_t value)
{
	ptrSpiCs->SetPinValue(pinCS, false);
	ptrSpiHw->Transmit(0x0Au);
	ptrSpiHw->Transmit(value);
	ptrSpiCs->SetPinValue(pinCS, true);
}

void Max7219Driver::SendDigit(uint8_t digit, uint8_t value)
{
	ptrSpiCs->SetPinValue(pinCS, false);
	ptrSpiHw->Transmit(digit + 1);
	ptrSpiHw->Transmit(value);
	ptrSpiCs->SetPinValue(pinCS, true);
}


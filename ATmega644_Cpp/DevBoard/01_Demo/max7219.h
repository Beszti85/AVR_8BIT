/*
 * max7219.h
 *
 * Created: 2021. 11. 06. 14:13:15
 *  Author: drCsabesz
 */ 


#ifndef MAX7219_H_
#define MAX7219_H_

#include "spi.h"
#include "IOPort.h"

class Max7219Driver
{
public:
	Max7219Driver( SpiMaster *ptrSpi, IOPort *ptrPortCs, uint8_t pinNumCS ) { ptrSpiHw = ptrSpi; ptrSpiCs = ptrPortCs; pinCS = pinNumCS; }
	void DisplayOnOff(bool value);
	void ScanLimit(uint8_t value);
	void DisplayTest(bool value);
	void SetIntensity(uint8_t value);
	void SendDigit(uint8_t digit, uint8_t value);
private:
	SpiMaster *ptrSpiHw;
	IOPort    *ptrSpiCs;
	uint8_t   pinCS;
};



#endif /* MAX7219_H_ */
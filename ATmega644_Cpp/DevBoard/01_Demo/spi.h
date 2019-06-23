/*
 * spi.h
 *
 * Created: 2019.06.01. 20:14:56
 *  Author: Beszterceiek
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "my_typedef.h"

enum SpiClockRate
{
    FoscPer4 = 0,
    FoscPer16,
    FoscPer64,
    FoscPer128,
};

class SpiMaster
{
protected:
    uint16_t baudrate;
public:
    SpiMaster(SpiClockRate clock_rate);
    uint16_t GetBaudRate(void) { return baudrate; };
    void Transmit(uint8_t data);
    uint8_t Receive(uint8_t addr);
};

extern SpiMaster Spi;

#endif /* SPI_H_ */
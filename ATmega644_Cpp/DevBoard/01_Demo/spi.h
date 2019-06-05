/*
 * spi.h
 *
 * Created: 2019.06.01. 20:14:56
 *  Author: Beszterceiek
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "my_typedef.h"

class SpiMaster
{
protected:
    uint16_t baudrate;
public:
    SpiMaster(uint16_t baud);
    void SpiMaster_Transmit(uint8_t data);
    uint8_t SpiMaster_Receive(uint8_t addr);
};

#endif /* SPI_H_ */
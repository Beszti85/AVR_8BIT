/*
 * spi.h
 *
 * Created: 2019.06.01. 20:14:56
 *  Author: Csaba Besztercei
 */ 


#ifndef SPI_H_
#define SPI_H_ 1

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
    ~SpiMaster() {};
};

inline void SpiMaster::Transmit(uint8_t data)
{
    /* Start transmission */
    SPDR = data;

    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));
}

inline uint8_t SpiMaster::Receive(uint8_t addr)
{
    /* Start transmission */
    SPDR = addr;

    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));

    addr = SPDR;

    return( addr );
}

extern SpiMaster Spi;

#endif /* SPI_H_ */
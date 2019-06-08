/*
 * spi.cpp
 *
 * Created: 2019.06.01. 20:15:19
 *  Author: Beszterceiek
 */ 

 #include "spi.h"

 SpiMaster::SpiMaster(uint16_t baud)
 {
    /* Port Init */
    DDRB |= 0xB0; // MOSI SCK SS output
    DDRB &= 0xBF; // MISO INPUT
    SPCR = 0;	/* Clear the register */
    SPSR = 0;
 }
 
 inline void SpiMaster::SpiMaster_Transmit(uint8_t data)
 {
    /* Start transmission */
    SPDR = data;

    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));
 }

 inline uint8_t SpiMaster::SpiMaster_Receive(uint8_t addr)
 {
    /* Start transmission */
    SPDR = addr;

    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));

    addr = SPDR;

    return( addr );
 }

 SpiMaster Spi = SpiMaster(1000);
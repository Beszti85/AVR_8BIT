/*
 * spi.cpp
 *
 * Created: 2019.06.01. 20:15:19
 *  Author: Beszterceiek
 */ 

 #include "spi.h"

 SpiMaster::SpiMaster(SpiClockRate clock_rate)
 {
    /* Port Init */
    #if (MCU_TYPE == MCU_MEGA32_644_1284)
    DDRB |= 0xA0; // MOSI SCK output, SS done by component
    DDRB &= 0xBF; // MISO INPUT
    #elif (MCU_TYPE == MCU_MEGA8_324)
    DDRB |= 0x28;
    DDRB &= 0xEF;
    #elif (MCU_TYPE == MCU_MEGA128_90)
    DDRB |= 0x06;
    DDRB &= 0xF7;
    #endif
    /* Enable SPI and set Master mode */
    SPCR = (1 << SPE) | (1 << MSTR) | (clock_rate << SPR0);
    SPSR = 0;
 }
 
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

 SpiMaster Spi = SpiMaster(FoscPer4);
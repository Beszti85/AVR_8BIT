/*
 * spi.cpp
 *
 * Created: 2019.06.01. 20:15:19
 *  Author: Beszterceiek
 */ 

 #include "spi.h"

 SpiMaster Spi = SpiMaster(FoscPer16);

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
 
 


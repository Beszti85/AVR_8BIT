 /*
 * 01_Demo.cpp
 *
 * Created: 2019.05.03. 8:22:15
 * Author : drcsabesz
 */ 

//#include <avr/io.h>
#include "IOPort.h"
#include "mcu_global.h"

int main(void)
{
	IOPort portB(&PORTB, &PINB, &DDRB);
	
	portB.SetPortDirection(0xFF);
    /* Replace with your application code */
    while (1) 
    {
        delay_msec(500);
        portB.TogglePin(0);
        Spi.Transmit(0xA5);
		//portB.SetPinValue(0, 1);
		//delay_msec(500);
		//portB.TogglePin(0);
		//portB.SetPinValue(0, 0);
    }
}


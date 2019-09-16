 /*
 * 01_Demo.cpp
 *
 * Created: 2019.05.03. 8:22:15
 * Author : Csaba Besztercei
 */ 

//#include <avr/io.h>
#include "IOPort.h"
#include "mcu_global.h"

int main(void)
{
    uint16_t tempu16;

	IOPort portB(&PORTB, &PINB, &DDRB);
    AdcHw.BaseInit();
	
	portB.SetPortDirection(0xFF);
    /* Replace with your application code */
    while (1) 
    {
        delay_msec(500);
        portB.TogglePin(0);
        Spi.Transmit(0xA5);
        tempu16 = AdcHw.SingleConversion(0);
		//portB.SetPinValue(0, 1);
		//delay_msec(500);
		//portB.TogglePin(0);
		//portB.SetPinValue(0, 0);
    }
}


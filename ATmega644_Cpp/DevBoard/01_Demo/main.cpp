 /*
 * 01_Demo.cpp
 *
 * Created: 2019.05.03. 8:22:15
 * Author : Csaba Besztercei
 */ 

//#include <avr/io.h>
#include "IOPort.h"
#include "mcu_global.h"
#include "adc_signal.h"

int main(void)
{
    uint16_t tempu16;

	IOPort portB(&PORTB, &PINB, &DDRB);
    AdcHw.BaseInit();
	Adc_SingleSig AdcSigCh0 = Adc_SingleSig(0, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh1 = Adc_SingleSig(1, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh2 = Adc_SingleSig(2, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh3 = Adc_SingleSig(3, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh4 = Adc_SingleSig(4, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh5 = Adc_SingleSig(5, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh6 = Adc_SingleSig(6, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh7 = Adc_SingleSig(7, 0, 1023u, 1023u);
	
	portB.SetPortDirection(0xFF);
    /* Replace with your application code */
    while (1) 
    {
        delay_msec(500);
        portB.TogglePin(0);
        Spi.Transmit(0xA5);
        AdcSigCh0.Conversion();
		AdcSigCh1.Conversion();
		AdcSigCh2.Conversion();
		AdcSigCh3.Conversion();
		AdcSigCh4.Conversion();
		AdcSigCh5.Conversion();
		AdcSigCh6.Conversion();
		AdcSigCh7.Conversion();
		//portB.SetPinValue(0, 1);
		//delay_msec(500);
		//portB.TogglePin(0);
		//portB.SetPinValue(0, 0);
    }
}


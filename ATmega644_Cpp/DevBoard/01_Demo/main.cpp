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
#include "timer.h"
#include "uart.h"
#include "spi.h"
#include <avr/interrupt.h>
#include "ds1621.h"
#include "max7219.h"

char InitString[] = "Hello World\n";

int main(void)
{
    uint16_t tempu16;
	uint16_t timerCycle1sec = 0u;
	char string1ms[] = "Timer 1sec elapsed!\n";
	bool displayToggle = false;
	
	Timer0 MyTimer0 = Timer0(TCCR0A_SETUP, TCCR0B_SETUP, 0x01u);

	IOPort portB(&PORTB, &PINB, &DDRB);
	portB.SetPortDirection(0x1F);
	
	SpiMaster Spi = SpiMaster(FoscPer16);
	
	Uart0.Init(9600u);
	
    AdcHw.BaseInit();
	Adc_SingleSig AdcSigCh0 = Adc_SingleSig(0, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh1 = Adc_SingleSig(1, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh2 = Adc_SingleSig(2, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh3 = Adc_SingleSig(3, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh4 = Adc_SingleSig(4, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh5 = Adc_SingleSig(5, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh6 = Adc_SingleSig(6, 0, 1023u, 1023u);
	Adc_SingleSig AdcSigCh7 = Adc_SingleSig(7, 0, 1023u, 1023u);
	
	//DS1621 Ds1621Ic = DS1621(&Spi);
	Max7219Driver Max7219 = Max7219Driver(&Spi, &portB, 4u);
	Max7219.DisplayOnOff(true);
	Max7219.ScanLimit(7u);
	
	portB.SetPinValue(4, true);
	/* Set Timer0A duty to 50% */
	MyTimer0.SetCompareValueA(0x7Fu);
	/* Send Init String via Uart */
	Uart0.Printf(InitString);
	Max7219.DisplayTest(false);
	// Enable interrupts
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		#if 1
		if( MyTimer0.GetIrqFlag() == true )
		{
			portB.TogglePin(0);
			portB.TogglePin(2);
			if( timerCycle1sec < 999u )
			{
				timerCycle1sec++;
			}
			else
			{
				portB.TogglePin(1);
				AdcSigCh0.Conversion();
				AdcSigCh1.Conversion();
				AdcSigCh2.Conversion();
				AdcSigCh3.Conversion();
				AdcSigCh4.Conversion();
				AdcSigCh5.Conversion();
				AdcSigCh6.Conversion();
				AdcSigCh7.Conversion();
				tempu16 = AdcSigCh0.GetResult();
				tempu16 >>= 2u;
				Uart0.Send((uint8_t)(tempu16));
				Uart0.Send('\n');
				Uart0.Printf(string1ms);
				portB.TogglePin(2);
				#if 0
				if(displayToggle == false)
				{
					Max7219.DisplayTest(true);
					displayToggle = true;
				}
				else
				{
					Max7219.DisplayTest(false);
					displayToggle = false;
				}
				#endif
				tempu16 >>= 2u;
				Max7219.SendDigit(0, 0x10u);
				Max7219.SendDigit(1, 0x30u);
				Max7219.SendDigit(2, 0x70u);
				Max7219.SendDigit(3, 0xFFu);
				Max7219.SendDigit(4, 0xFFu);
				Max7219.SendDigit(5, 0x70u);
				Max7219.SendDigit(6, 0x30u);
				Max7219.SendDigit(7, 0x10u);
				Max7219.SetIntensity((uint8_t)tempu16);
				timerCycle1sec = 0u;
			}
			// Clear IT flag
			MyTimer0.ClearIrqFlag();
			portB.TogglePin(2);
		}
		#elif 0
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
		tempu16 = AdcSigCh0.GetResult();
		tempu16 >>= 2u;
		MyTimer0.SetCompareValueA((uint8_t)(tempu16));
		//Uart0.Send((uint8_t)(tempu16));
		if( MyTimer0.GetIrqFlag() )
		{
			portB.TogglePin(1);
		}
		#else
		delay_msec(200);
		PORTB |= 0x01u;
		delay_msec(400);
		PORTB &= 0xFEu;
		#endif
    }
}


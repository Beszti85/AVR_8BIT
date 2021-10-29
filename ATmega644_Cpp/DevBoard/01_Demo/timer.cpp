/*
 * timer.cpp
 *
 * Created: 2019.06.20. 6:34:04
 *  Author: Beszterceiek
 */ 

#include "timer.h"
#include <avr/interrupt.h>
#include "ProjectConfig.h"

/******************* TIMER0 **********************/
volatile bool IrqFlag;

#if (TIMER0_OVERFLOW_IT == 1)
ISR(TIMER0_OVF_vect)
{
	IrqFlag = true;	
}
#endif

#if (TIMER0_COMPARE_IT == 1)

ISR(TIMER0_COMPA_vect)
{
	IrqFlag = true;	
}
#endif


Timer0::Timer0(uint32_t frequency)
{
}

Timer0::Timer0(uint8_t vTCCR0A, uint8_t vTCCR0B, uint8_t vTIMSK0)
{
	TCCR0A = vTCCR0A;
	TCCR0B = vTCCR0B;
	TIMSK0 = vTIMSK0;
	TCNT0  = 0u;
	OCR0A  = 0u;
	OCR0B  = 0u;
}

bool Timer0::GetIrqFlag(void)
{
	return IrqFlag;
}

void Timer0::ClearIrqFlag(void)
{
	IrqFlag = false;
}

/******************* TIMER1 **********************/

Timer1::Timer1(uint32_t frequency)
{

}

Timer1::Timer1(uint8_t vTCCR1A, uint8_t vTCCR1B, uint8_t vTIMSK1)
{
	TCCR1A = vTCCR1A;
	TCCR1B = vTCCR1B;
	TIMSK1 = vTIMSK1;
}
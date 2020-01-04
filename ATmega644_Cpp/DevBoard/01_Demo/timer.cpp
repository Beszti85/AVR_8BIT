/*
 * timer.cpp
 *
 * Created: 2019.06.20. 6:34:04
 *  Author: Beszterceiek
 */ 

#include "timer.h"

/******************* TIMER0 **********************/

Timer0::Timer0(uint32_t frequency)
{

}

Timer0::Timer0(uint8_t vTCCR0A, uint8_t vTCCR0B, uint8_t vTIMSK0)
{
	TCCR0A = vTCCR0A;
	TCCR0B = vTCCR0B;
	TIMSK0 = vTIMSK0;
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
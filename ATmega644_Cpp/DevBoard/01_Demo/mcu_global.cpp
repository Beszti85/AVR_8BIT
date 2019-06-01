/*
 * mcu_global.cpp
 *
 * Created: 2019.05.27. 16:31:06
 *  Author: Beszterceiek
 */ 

 /*********************** DELAY_FUNCTION ***************************/

#include "mcu_global.h"

void delay_msec (uint16_t msec)
{
    unsigned short i = 0;
    for (i = 0; i < msec; i++)
    {
        _delay_ms(1);
    }
}

void delay_usec (uint16_t usec)
{
    unsigned short i = 0;
    for (i = 0; i < usec; i++)
    {
        _delay_us(1);
    }
}
/******************************************************************/
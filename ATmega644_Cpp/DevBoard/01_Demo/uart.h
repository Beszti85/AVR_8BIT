/*
 * uart.h
 *
 * Created: 2019.09.16. 21:17:38
 *  Author: Csaba Besztercei
 */ 


#ifndef UART_H_
#define UART_H_

#include "my_typedef.h"

extern "C" void USART0_RX_vect(void) __attribute__ ((signal));

class Uart
{
protected:
    vuint8_t gUartData;
public:
    Uart() {};
    friend void USART0_RX_vect(void);
};

#endif /* UART_H_ */
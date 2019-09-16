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
    void Send(uint8_t data);
};

inline void Uart::Send(uint8_t data)
{
    /* Wait for empty transmit buffer */
    while( !(UCSR0A & (1<<UDRE0)) );
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

#endif /* UART_H_ */
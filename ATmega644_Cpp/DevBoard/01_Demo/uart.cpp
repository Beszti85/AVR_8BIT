/*
 * uart.cpp
 *
 * Created: 2019.09.16. 21:18:15
 *  Author: Csaba Besztercei
 */ 

#include "uart.h"

Uart Uart0 = Uart();

ISR(USART0_RX_vect)
{
    //Set_uart_rx_complete(True);
    Uart0.gUartData = UDR0;
}
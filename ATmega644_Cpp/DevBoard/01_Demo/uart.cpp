/*
 * uart.cpp
 *
 * Created: 2019.09.16. 21:18:15
 *  Author: Csaba Besztercei
 */ 

#include "uart.h"
#include "ProjectConfig.h"

Uart Uart0 = Uart();

ISR(USART0_RX_vect)
{
    //Set_uart_rx_complete(True);
    Uart0.gUartData = UDR0;
}

void Uart::Init(uint32_t baud)
{
    /* calculate UBRR value */
    UBRR0 = (uint16_t)((uint32_t)F_CPU / 16u / baud - 1u);
    /* Enable Rx, Tx and Rx IT */
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    /* Synchronous mode, no parity 1 stop bit, 8-bit frames */
    UCSR0C = (2 << UMSEL00) | (0 << UPM01) |(0 << UPM00) | (1 << USBS0) | (3 << UCSZ00);
}

#ifndef _MY_TYPEDEF_H_
#define _MY_TYPEDEF_H_ 1

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL

typedef volatile unsigned char 	vuint8_t;
typedef unsigned char 			uint8_t;
typedef unsigned int 			uint16_t;
typedef volatile unsigned int 	vuint16_t;
typedef unsigned long 			uint32_t;

typedef volatile signed char 	vsint8_t;
typedef signed char				sint8_t;
typedef signed int				sint16_t;
typedef signed long				sint32_t;

typedef volatile uint8_t register8_t;

/*
#define PINA	(*(register8_t*) 0x20)
#define DDRA	(*(register8_t*) 0x21)
#define PORTA	(*(register8_t*) 0x22)
*/

/* Processor TYPE */
#define MCU_MEGA32_644_1284 0 
#define MCU_MEGA8_324       1
#define MCU_MEGA128_90      2

#define MCU_TYPE            MCU_MEGA32_644_1284

#define True	1
#define False	0

#endif /* _MY_TYPEDDEF_H */

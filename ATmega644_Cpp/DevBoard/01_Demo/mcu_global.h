/*
 * mcu_global.h
 *
 * Created: 2019.05.27. 16:31:26
 *  Author: Beszterceiek
 */ 


#ifndef MCU_GLOBAL_H_
#define MCU_GLOBAL_H_

#include "my_typedef.h"
#include <util/delay.h>
#include "spi.h"

/************ Function definitions *****************/
void delay_usec (uint16_t msec);
void delay_msec (uint16_t msec);
/***************************************************/

#endif /* MCU_GLOBAL_H_ */
/*
 * DS1621.h
 *
 * Created: 2021. 11. 01. 17:04:00
 *  Author: drCsabesz
 */ 


#ifndef DS1621_H_
#define DS1621_H_

#include "my_typedef.h"
#include "spi.h"

/* HW ADDRESSES */
#define DS1621ADDR_R 0x91 /* 145 */
#define DS1621ADDR_W 0x90 /* 144 */

/* COMMAND BYTES */
#define READ_TMP  0xAA /* 170 */
#define TEMP_LOW  0xA1 /* 161 */
#define TEMP_HIGH 0xA2 /* 162 */
#define CONF_REG  0xAC /* 172 */
#define READ_CNT  0xA8 /* 168 */
#define READ_SLP  0xA9 /* 169 */
#define START_MES 0xEE /* 238 */
#define STOP_MES  0x22 /* 34 */

class DS1621
{
	public:
	DS1621( SpiMaster* ptrSpi ) { SpiHw = ptrSpi; }
	private:
	SpiMaster* SpiHw;
};




#endif /* DS1621_H_ */
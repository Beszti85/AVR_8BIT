#include "ds1621.h"

#if 0
void DS1621Config (uint8 data)
{
	I2CStart();
	I2CWrite(DS1621ADDR_W);
	I2CWrite(CONF_REG);
	I2CWrite(data);
	I2CStop();
}

void DS1621Init (void)
{
	I2CStart();
	I2CWrite(DS1621ADDR_W);
	I2CWrite(CONF_REG);
	I2CWrite(0x00);
	I2CStop();
}

void DS1621StartMeasure(void)
{
	I2CStart();
	I2CWrite(DS1621ADDR_W);
	I2CWrite(START_MES);
	I2CStop();
}

/* 8 bit mode */
uint8 DS1621ReadTemp (void)
{
	uint8 retval;
	I2CStart();
	I2CWrite(DS1621ADDR_W);
	I2CWrite(READ_TMP);
	I2CStart();
	I2CWrite(DS1621ADDR_R);
	retval = I2CRead(0);
	I2CStop();
	return retval;
}


uint8 DS1621ReadConf (void)
{
	uint8 retval;
	I2CStart();
	I2CWrite(DS1621ADDR_W);
	I2CWrite(CONF_REG);
	I2CStart();
	I2CWrite(DS1621ADDR_R);
	retval = I2CRead(0);
	I2CStop();
	return retval;
}
#endif

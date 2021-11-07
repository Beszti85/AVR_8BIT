#include "ds1307.h"


/* Init to fix value 181h 37  */
/* 2014/01/28 Tuesday */
void DS1307_Init (void)
{
    I2CStart();
    I2CWrite(DS1307ADDR_W);
    I2CWrite(REG_SECONDS);
    I2CWrite(0);
    I2CWrite(0x03);
    I2CWrite(0x11);
    I2CWrite(0x03);
    I2CWrite(0x28);
    I2CWrite(0x12);
    I2CWrite(0x16);
    I2CWrite(0x00);
    I2CStop();
}

/* Init to fix value 181h 37  */
/* 2014/01/28 Tuesday */
void DS1307_Set_Date (void)
{
    I2CStart();
    I2CWrite(DS1307ADDR_W);
    I2CWrite(REG_DAY);
    I2CWrite(0x02);
    I2CWrite(0x20);
    I2CWrite(0x12);
    I2CWrite(0x16);
    I2CWrite(0x00);
    I2CStop();
}

/* Allow 1 sec SQWE output */
void DS1307_Pulse_1Hz (void)
{
    I2CStart();
    I2CWrite(DS1307ADDR_W);
    I2CWrite(REG_CONTROL);
    I2CWrite(0x10);
    I2CStop();
}

void DS1307_Read_Date (uint8 *day, uint8 *date, uint8 *month, uint8 *year)
{
	I2CStart();
	I2CWrite(DS1307ADDR_W);
	I2CWrite(REG_DAY);
	I2CStart();
	I2CWrite(DS1307ADDR_R);
	*day = I2CRead(1);
	*date = I2CRead(1);
	*month = I2CRead(1);
	*year = I2CRead(0);
	I2CStop();
}

void DS1307_Read_Time (uint8 *sec, uint8 *min, uint8 *hour)
{
	I2CStart();
	I2CWrite(DS1307ADDR_W);
	I2CWrite(REG_SECONDS);
	I2CStart();
	I2CWrite(DS1307ADDR_R);
	*sec = I2CRead(1);
	*min = I2CRead(1);
	*hour = I2CRead(0);
	I2CStop();
}

void DS1307_Convert_Time (char *s, uint8 hour, uint8 min, uint8 sec)
{
	/* fix size: 9 */ 
	s[0] = ((hour >> 4) & 0x03) + '0';
	s[1] = (hour & 0x0F) + '0';
	s[2] = ':';
	s[3] = (min >> 4) +'0';
	s[4] = (min & 0x0F) + '0';
	s[5] = ':';
	s[6] = (sec >> 4) +'0';
	s[7] = (sec & 0x0F) + '0';
	s[8] = '\0';
}

void DS1307_Convert_Date (char *s, uint8 year, uint8 month, uint8 date)
{
	/* fix size: 9 */
	s[0] = '2';
	s[1] = '0';
	s[2] = ((year >> 4) & 0x0F) + '0';
	s[3] = (year & 0x0F) + '0';
	s[4] = '/';
	s[5] = ((month >> 4) & 0x01)+'0';
	s[6] = (month & 0x0F) + '0';
	s[7] = '/';
	s[8] = ((date >> 4) & 0x03) +'0';
	s[9] = (date & 0x0F) + '0';
	s[10] = '\0';
}

void DS1307_ROM_WriteB (uint8 address, uint8 data)
{
	I2CStart();
	I2CWrite(DS1307ADDR_W);
	I2CWrite(address);
	I2CWrite(data);
	I2CStop();
}

uint8 DS1307_ROM_ReadB (uint8 address)
{
	uint8 retval;
	I2CStart();
	I2CWrite(DS1307ADDR_W);
	I2CWrite(address);
	I2CStart();
	I2CWrite(DS1307ADDR_R);
	retval = I2CRead(0);
	I2CStop();
	return retval;
}

uint8 DS1307_ROM_ReadB_Debug (uint8 address)
{
	uint8 retval;
	retval = I2CStart();
	retval |= (I2CWrite(DS1307ADDR_W) << 1);
	retval |= (I2CWrite(address) << 2);
	retval |= (I2CStart() << 3);
	retval |= (I2CWrite(DS1307ADDR_R) << 4);
	//retval = I2CRead(0);
	I2CStop();
	return retval;
}

void DS1307_Set_Out (uint8 value)
{
	I2CStart();
    I2CWrite(DS1307ADDR_W);
    I2CWrite(REG_CONTROL);
	if (value)
	{
    	I2CWrite(0x80);
	}
	else
	{
		I2CWrite(0x00);
	}
    I2CStop();
}




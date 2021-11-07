#include "mcu_global.h"

/* ADDRESS: 0xD0 */

#define DS1307ADDR_R 0xD1
#define DS1307ADDR_W 0xD0

#define REG_SECONDS 0x00
#define REG_MINUTES 0x01
#define REG_HOURS   0x02
#define REG_DAY     0x03
#define REG_DATE    0x04
#define REG_MONTH   0x05
#define REG_YEAR    0x06
#define REG_CONTROL 0x07

#define RAM_START   0x09
#define RAM_END     0x3F

#define RAM_SIZE    56

void DS1307_Init (void);
void DS1307_Set_Date (void);
void DS1307_Pulse_1Hz (void);
void DS1307_Read_Date (uint8 *day, uint8 *date, uint8 *month, uint8 *year);
void DS1307_Read_Time (uint8 *sec, uint8 *min, uint8 *hour);
void DS1307_Convert_Time (char *s, uint8 hour, uint8 min, uint8 sec);
void DS1307_Convert_Date (char *s, uint8 year, uint8 month, uint8 date);

void DS1307_ROM_WriteB (uint8 address, uint8 data);
uint8 DS1307_ROM_ReadB (uint8 address);
uint8 DS1307_ROM_ReadB_Debug (uint8 address);
void DS1307_Set_Out (uint8 value);

/*
 * i2c.h
 *
 * Created: 2019.08.24. 14:41:10
 *  Author: Besztercei
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "my_typedef.h"

#define TW_STATUS (TWSR & 0xF8)

class I2CMaster
{
protected:

public:
    I2CMaster(uint16_t speed);
    uint8_t Start (void);
    void Stop(void);
    uint8_t Write(uint8_t data);
    uint8_t Read(uint8_t ack, uint8_t* data);
};

inline uint8_t I2CMaster::Start(void)
{
    TWCR = ((1 << TWINT) | (1 << TWEN) | (1 << TWSTA)); /* Clear IT flag, send start condition */
    while (!(TWCR & (1 << TWINT)))
    {
        ;
    }
    return ((TW_STATUS == 0x08) || (TW_STATUS == 0x10));
}

inline void I2CMaster::Stop(void)
{
    TWCR = ((1 << TWINT) | (1 << TWEN) | (1 << TWSTO));
}

inline uint8_t I2CMaster::Write(uint8_t data)
{
    TWDR = data;
    TWCR = ((1 << TWINT) | (1 << TWEN));
    while (!(TWCR & (1 << TWINT)))
    {
        ;
    }
    return (TW_STATUS != 0x28);
}

inline uint8_t I2CMaster::Read(uint8_t ack, uint8_t* data)
{
    uint8_t retval;
    if (ack)
    {
        TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
    }
    else
    {
        TWCR = (1<<TWINT) | (1<<TWEN);
    }
    while (!(TWCR & (1 << TWINT)))
    {
        ;
    }
    *retval = TWDR;
    return (TW_STATUS != 0x28);
}

#endif /* I2C_H_ */
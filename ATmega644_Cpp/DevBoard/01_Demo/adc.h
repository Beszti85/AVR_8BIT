/*
 * adc.h
 *
 * Created: 2019.05.27. 17:02:39
 *  Author: Beszterceiek
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "my_typedef.h"

class Adc
{
protected:
    uint8_t  channel;
    uint16_t rawValue;
public:
    Adc(uint8_t chan);
    Adc(uint8_t vADMUX, uint8_t vADCSRA, uint8_t vADCSRB, uint8_t vDIDR0);
    void SetVref(uint8_t ref);
    void SetChannel(uint8_t chan);
    void SetPrescaler(uint8_t prescale);
    void StartConversion(void);
    uint16_t StartAndGetConversion(void);
    uint16_t GetResult(void);
};



#endif /* ADC_H_ */
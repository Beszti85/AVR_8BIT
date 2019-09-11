/*
 * adc.h
 *
 * Created: 2019.05.27. 17:02:39
 *  Author: Beszterceiek
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "my_typedef.h"

enum VoltRef
{
    Internal = 0u,
    eAVCC,
    int1_1V,
    int2_56V
};

enum Prescale
{
    DefDiv2 = 0,
    DivBy2,
    DivBy4,
    DivBy8,
    DivBy16,
    DivBy32,
    DivBy64,
    DivBy128
};

class Adc
{
protected:
    uint8_t  channel;
    uint16_t rawValue;
public:
    Adc(void) {};
    Adc(uint8_t vADMUX, uint8_t vADCSRA, uint8_t vADCSRB, uint8_t vDIDR0);
    void SetVref(VoltRef ref);
    void SetChannel(uint8_t chan);
    void SetPrescaler(Prescale value);
    void StartConversion(void)   {ADCSRA |= 0x40u;};
    void LeftAdjustResult(void)  {ADMUX |= (1 << ADLAR);};
    void RightAdjustResult(void) {ADMUX &= 0xDFu;};
    uint16_t StartAndGetConversion(void);
    uint16_t GetResult(void);
};

inline void Adc::SetVref(VoltRef ref)
{
    /* Clear bits 6 and 7 */
    ADMUX &= 3Fu;
    /* Set value */
    ADMUX |= (ref << 6);
}

inline void Adc::SetChannel(uint8_t chan)
{
    /* clear bits 0..4 */
    ADMUX &= 0xE0u;
    /* set value */
    ADMUX |= chan;
}

inline void Adc::SetPrescaler(Prescale value)
{
    /* clear bits 0..2 */
    ADCSRA &= 0xF8u;
    /* value */
    ADCSRA |= value;
}

#endif /* ADC_H_ */
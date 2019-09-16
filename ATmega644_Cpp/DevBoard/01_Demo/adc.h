/*
 * adc.h
 *
 * Created: 2019.05.27. 17:02:39
 *  Author: Csaba Besztercei
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

enum AutoTriggerSource
{
    FreeRunning = 0,
    AnalogComparator,
    ExternalInterrupt0,
    Timer0Compare,
    Timer0Overflow,
    Timer1CompareB,
    Timer1Overflow,
    Timer1Capture
};

class Adc
{
protected:
    uint8_t  channel;
    uint16_t rawValue;
public:
    Adc(void) {};
    Adc(uint8_t vADMUX, uint8_t vADCSRA, uint8_t vADCSRB, uint8_t vDIDR0);
    void BaseInit();
    void SetVref(VoltRef ref);
    void SetChannel(uint8_t chan);
    void SetPrescaler(Prescale value);
    void SetAutoTriggerSource(AutoTriggerSource value) {ADCSRB = value;};
    void StartConversion(void)   {ADCSRA |= 0x40u;};
    void WaitForConversionComplete(void) {while (ADCSRA & (1 << ADSC));};
    void LeftAdjustResult(void)  {ADMUX |= (1 << ADLAR);};
    void RightAdjustResult(void) {ADMUX &= 0xDFu;};
    uint16_t SingleConversion(uint8_t channel);
    uint16_t GetResult10bits(void);
};

inline void Adc::SetVref(VoltRef ref)
{
    /* Clear bits 6 and 7 */
    ADMUX &= 0x3Fu;
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

inline uint16_t Adc::GetResult10bits(void)
{
    /* LeftAdjusted */
    if (ADCSRA & (1 << ADLAR))
    {
        return (((uint16_t)(ADCL) >> 6u) | ((uint16_t)(ADCH) << 2u));
    }
    else
    {
        return ((uint16_t)(ADCL) | ((uint16_t)(ADCH) << 8u));
    }
}

extern Adc AdcHw;

#endif /* ADC_H_ */
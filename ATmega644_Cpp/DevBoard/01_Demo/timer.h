/*
 * timer.h
 *
 * Created: 2019.06.20. 6:33:52
 *  Author: Beszterceiek
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "my_typedef.h"

class BaseTimer
{
protected:
    uint32_t tFreq;
public:
    virtual void StartTimer(void);
    virtual void StopTimer(void);
    virtual uint16_t GetCnValue(void);
    virtual void SetFrequency(uint32_t frequency);
};

class Timer0 : BaseTimer
{
public:
    Timer0(uint32_t frequency);
	Timer0(uint8_t vTCCR0A, uint8_t vTCCR0B, uint8_t vTIMSK0);
    uint16_t GetCntValue(void) {return (uint16_t)TCNT0;};
    void StartTimer(void);
    void StopTimer(void) {TCCR0B &= 0xC8;};
    void SetFrequency(uint32_t frequency);
protected:
    uint8_t  cnt_val;
};

class Timer1 : BaseTimer
{
public:
    Timer1(uint32_t frequency);
	Timer1(uint8_t vTCCR1A, uint8_t vTCCR1B, uint8_t vTIMSK1);
    uint16_t GetCntValue(void) {return TCNT1;};
    void StartTimer(void);
    void StopTimer(void) {TCCR1B &= 0xD8;};
    void SetFrequency(uint32_t frequency);
protected:
    uint16_t cnt_val;
};

class Timer2 : BaseTimer
{
public:
    Timer2(uint32_t frequency);
    uint16_t GetCntValue(void) {return TCNT2;};
    void StartTimer(void);
    void StopTimer(void) {TCCR2B &= 0xC8;};
    void SetFrequency(uint32_t frequency);
protected:
    uint16_t cnt_val;
};

#endif /* TIMER_H_ */
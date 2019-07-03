/*
 * timer.h
 *
 * Created: 2019.06.20. 6:33:52
 *  Author: Beszterceiek
 */ 


#ifndef TIMER_H_
#define TIMER_H_

class Timer0
{
public:
    uint8_t GetCntValue(void) {return TCNT0;};
    Timer0(uint16_t frequency);
    void StartTimer(void);
    void StopTimer(void);
protected:
    uint16_t frequ;
    uint8_t  cnt_val;
};

class Timer1
{
public:
    uint16_t GetCntValue(void) {return TCNT1;};
    Timer1(uint16_t frequency);
    void StartTimer(void);
    void StopTimer(void);
protected:
    uint16_t frequ;
    uint16_t cnt_val;
}



#endif /* TIMER_H_ */
/*
 * adc_signal.h
 *
 * Created: 2019.10.09. 13:22:47
 *  Author: drcsabesz
 */ 


#ifndef ADC_SIGNAL_H_
#define ADC_SIGNAL_H_

#include "my_typedef.h"
#include "adc.h"

class Adc_SingleSig : Adc
{
protected:
	uint16_t RawValue;
	uint16_t MinValue;
	uint16_t MaxValue;
	uint8_t  Error;
	uint8_t  ErrorValue;
	uint8_t  ChannelNum;
public:
	Adc_SingleSig(uint8_t channel, uint16_t min, uint16_t max, uint16_t err);
	void Conversion(void);
	void MeasureRawValue(void);
};



#endif /* ADC_SIGNAL_H_ */
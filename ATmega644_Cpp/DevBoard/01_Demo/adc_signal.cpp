/*
 * adc_signal.cpp
 *
 * Created: 2019.10.09. 13:21:43
 *  Author: drcsabesz
 */ 

#include "adc_signal.h"

Adc_SingleSig::Adc_SingleSig(uint8_t channel, uint16_t min, uint16_t max, uint16_t err)
{
	ChannelNum = channel;
	MinValue   = min;
	MaxValue   = max;
	ErrorValue = err;
}

void Adc_SingleSig::Conversion()
{
	/* select channel */
	this->SetChannel(ChannelNum & 0x0Fu);
	/* start conversion */
	this->StartConversion();
	/* wait for the result */
	this->WaitForConversionComplete();
	/* get result */
	RawValue = this->GetResult10bits();
}
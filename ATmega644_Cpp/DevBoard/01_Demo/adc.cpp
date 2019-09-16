/*
 * adc.cpp
 *
 * Created: 2019.05.27. 17:02:27
 *  Author: Csaba Besztercei
 */ 
#include "adc.h"
#include "ProjectConfig.h"

Adc AdcHw = Adc();

Adc::Adc(uint8_t vADMUX, uint8_t vADCSRA, uint8_t vADCSRB, uint8_t vDIDR0)
{
    ADMUX  = vADMUX;
    ADCSRA = vADCSRA;
    ADCSRB = vADCSRB;
    DIDR0  = vDIDR0;
}

void Adc::BaseInit()
{
    ADMUX  = ADMUX_SETUP;
    ADCSRA = ADCSRA_SETUP;
    DDRA  &= ADC_PORTS_0;
    ADCSRB = 0u;
}

uint16_t Adc::SingleConversion(uint8_t channel)
{
    /* select channel */
    this->SetChannel(channel & 0x0Fu);
    /* start conversion */
    this->StartConversion();
    /* wait for the result */
    this->WaitForConversionComplete();
    /* get result */
    return (this->GetResult10bits());
}



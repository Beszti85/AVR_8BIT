/*
 * adc.cpp
 *
 * Created: 2019.05.27. 17:02:27
 *  Author: Csaba Besztercei
 */ 
 #include "adc.h"


 Adc::Adc(uint8_t vADMUX, uint8_t vADCSRA, uint8_t vADCSRB, uint8_t vDIDR0)
 {
    
 }

 uint16_t Adc::StartAndGetConversion(uint8_t channel)
 {
    /* select channel */
    this->SetChannel(channel);
    /* start conversion */
    this->StartConversion();
    /* wait for the result */
    this->WaitForConversionComplete();
    /* get result */
    return (this->GetResult10bits());
 }
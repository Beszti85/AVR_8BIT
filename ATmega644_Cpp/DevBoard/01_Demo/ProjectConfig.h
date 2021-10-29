/*
 * ProjectConfig.h
 *
 * Created: 2019.09.15. 21:04:24
 *  Author: Csaba Besztercei
 */ 


#ifndef PROJECTCONFIG_H_
#define PROJECTCONFIG_H_

/************* STRAPS ****************/

#define	LED_BLINKING            0
#define	TIMER0_OVERFLOW_IT      1
#define TIMER0_COMPARE_IT       0
#define	TIMER1_OVERFLOW_IT      0
#define TIMER1_COMPARE_A_IT     0
#define TIMER1_PWM_A            1
#define TIMER1_PWM_B            1
#define TIMER1_COMPARE_B_IT     0
#define TIMER1_CAPTURE_IT       0
#define TIMER2_OVERFLOW_IT      0
#define TIMER2_ASYNCHRONE       0
#define TIMER2_COMPARE          1
#define TIMER2_COMPARE_IT       0
#define	EXTERNAL_INT0           0
#define EXTERNAL_INT1           0
#define EXTERNAL_INT2           0

#define TIMER0_CONFIGURED       1
#define TIMER1_CONFIGURED       1
#define TIMER2_CONFIGURED       0

#define I2C_CONFIGURED          0
#define ADC_CONFIGURED          1
#define SPI_CONFIGURED          0
#define USART_CONFIGURED        0

#define LCD_USED                0

/*************************************/

#define F_CPU 16000000UL

/************ TIMER0_SETUP ***********/

#if (!TIMER0_CONFIGURED)
#define TCCR0A_SETUP   0
#define TCCR0B_SETUP   0

#elif (TIMER0_OVERFLOW_IT)

#define TCCR0A_BIT76   0 /* COMPARE_OUTPUT_MODE_A */
#define TCCR0A_BIT54   0 /* COMPARE_OUTPUT_MODE_B */
#define TCCR0A_BIT10   0 /* WAWEFORM_GENERATION_MODE_BIT 10 */

#define TCCR0A_SETUP   ((TCCR0A_BIT76 << COM0A0) | (TCCR0A_BIT54 << COM0B0) | (TCCR0A_BIT10 << WGM00))

#define TCCR0B_BIT7    0 /* FORCE_OUTPUT_COMPARE_A */
#define TCCR0B_BIT6    0 /* FORCE_OUTPUT_COMPARE_B */
#define TCCR0B_BIT3    0 /* WAVEFORM_GENERATION_MODE BIT 2 */
#define TCCR0B_BIT210  3 /* PRESCALER BITS 0...7 */

#define TCCR0B_SETUP   ((TCCR0B_BIT7 << FOC0A) | (TCCR0B_BIT6 << FOC0B) | (TCCR0B_BIT3 << WGM02) | (TCCR0B_BIT210 << CS00))

#else

#define TCCR0A_BIT76   1 /* COMPARE_OUTPUT_MODE_A */
#define TCCR0A_BIT54   0 /* COMPARE_OUTPUT_MODE_B */
#define TCCR0A_BIT10   2 /* WAWEFORM_GENERATION_MODE_BIT 10 */

#define TCCR0A_SETUP   ((TCCR0A_BIT76 << COM0A0) | (TCCR0A_BIT54 << COM0B0) | (TCCR0A_BIT10 << WGM00))

#define TCCR0B_BIT7    0 /* FORCE_OUTPUT_COMPARE_A */
#define TCCR0B_BIT6    0 /* FORCE_OUTPUT_COMPARE_B */
#define TCCR0B_BIT3    0 /* WAVEFORM_GENERATION_MODE BIT 2 */
#define TCCR0B_BIT210  3 /* PRESCALER BITS 0...7 */

#define TCCR0B_SETUP   ((TCCR0B_BIT7 << FOC0A) | (TCCR0B_BIT6 << FOC0B) | (TCCR0B_BIT3 << WGM02) | (TCCR0B_BIT210 << CS00))

#endif

/*************************************/

/************ TIMER1_SETUP ***********/
#if (!TIMER1_CONFIGURED)
#define TIMER1_SETUP_A   0
#define TIMER1_SETUP_B   0
#else

#define TCCR1A_BIT76   2 /* COMPARE_OUTPUT_MODE_A */
#define TCCR1A_BIT54   2 /* COMPARE_OUTPUT_MODE_B 0 */
#define TCCR1A_BIT10   3 /* WAVEFROM_GENERATION_MODE_LOWER_BITS */

#define TIMER1_SETUP_A ((TCCR1A_BIT76 << COM1A0) | (TCCR1A_BIT54 << COM1B0) | (TCCR1A_BIT10 << WGM10))

#define TCCR1B_BIT7    0 /* INPUT_CAPTURE_NOISE_REDUCTION */
#define TCCR1B_BIT6    0 /* INPUT_CAPTURE_EDGE_SELECT */
#define TCCR1B_BIT43   1 /* WAVEFORM_GENERATION_MODE_HIGHER_BITS */
#define TCCR1B_BIT210  2 /* PRESCALER BITS 0...7 */

#define TIMER1_SETUP_B ((TCCR1B_BIT7 << ICNC1) | (TCCR1B_BIT6 << ICES1) | (TCCR1B_BIT43 << WGM12) | (TCCR1B_BIT210 << CS10))

#endif

/*************************************/

/************ TIMER2_SETUP ***********/

#if (!TIMER2_CONFIGURED)
#define TCCR2A_SETUP   0
#define TCCR2B_SETUP   0
#else

#define TCCR2A_BIT76   2 /* COMPARE_OUTPUT_MODE_A */
#define TCCR2A_BIT54   0 /* COMPARE_OUTPUT_MODE_B */
#define TCCR2A_BIT10   3 /* WAWEFORM_GENERATION_MODE_BIT 10 */

#define TCCR2A_SETUP   ((TCCR2A_BIT76 << COM2A0) | (TCCR2A_BIT54 << COM2B0) | (TCCR2A_BIT10 << WGM20))

#define TCCR2B_BIT7    0 /* FORCE_OUTPUT_COMPARE_A */
#define TCCR2B_BIT6    0 /* FORCE_OUTPUT_COMPARE_B */
#define TCCR2B_BIT3    0 /* WAVEFORM_GENERATION_MODE BIT 2 */
#define TCCR2B_BIT210  5 /* PRESCALER BITS 0...7 */

#define TCCR2B_SETUP   ((TCCR2B_BIT7 << FOC2A) | (TCCR2B_BIT6 << FOC2B) | (TCCR2B_BIT3 << WGM22) | (TCCR2B_BIT210 << CS20))

#endif

/*************************************/

/************* ADC_SETUP *************/

#if (!ADC_CONFIGURED)
#define ADMUX_SETUP    0
#else
#define ADMUX_BIT76    1 /* REFERENCE_SELECTION_BIT 0...3 */
#define ADMUX_BIT5     0 /* ADC_LEFT_ADJUST */
#define ADMUX_BIT40    0 /* ADC_CHANNEL_AND_GAIN_SEL 0.32 */

#define ADMUX_SETUP ((ADMUX_BIT76 << 6) | (ADMUX_BIT5 << 5) |(ADMUX_BIT40))
#endif

#if (!ADC_CONFIGURED)
#define ADCSRA_SETUP   0
#else
#define ADCSRA_BIT7    1 /* ADC_ENABLE */
#define ADCSRA_BIT6    0 /* START_CONVERSION */
#define ADCSRA_BIT5    0 /* AUTO_TRIGGER_ENABLE */
#define ADCSRA_BIT4    0 /* INTERRUPT_FLAG */
#define ADCSRA_BIT3    0 /* INTERRUPT_ENABLE */
#define ADCSRA_BIT210  3 /* PRESCALER_BITS 0...7 */

#define ADCSRA_SETUP ((ADCSRA_BIT7 << 7) | (ADCSRA_BIT6 << 6) | (ADCSRA_BIT5 << 5) | (ADCSRA_BIT4 << 4) | (ADCSRA_BIT3 << 3) | (ADCSRA_BIT210))
#endif

#define ADC0_USED  1 /* 0 - channel not used, 1 - used */
#define ADC1_USED  1
#define ADC2_USED  1
#define ADC3_USED  1
#define ADC4_USED  1
#define ADC5_USED  1
#define ADC6_USED  1
#define ADC7_USED  1

#define ADC_PORTS     (ADC0_USED | \
(ADC1_USED << 1) | \
(ADC2_USED << 2) | \
(ADC3_USED << 3) | \
(ADC4_USED << 4) | \
(ADC5_USED << 5) | \
(ADC6_USED << 6) | \
(ADC7_USED << 7))

/*************************************/

/************* SPI_SETUP *************/

#if (!SPI_CONFIGURED)
#define SPCR_BIT7      0 /* SPI_IT_ENABLE */
#define SPCR_BIT6      0 /* SPI_ENABLE */
#define SPCR_BIT5      0 /* DATA_ORDER - 0:LSB 1st, 1:MSB 1st */
#define SPCR_BIT4      0 /* MASTER - 1 / SLAVE - 0 */
#define SPCR_BIT3      0 /* CLOCK_POLARITY */
#define SPCR_BIT2      0 /* CLOCK_PHASE */
#define SPCR_BIT10     0 /* CLOCK_RATE */
#else
#define SPCR_BIT7      0 /* SPI_IT_ENABLE */
#define SPCR_BIT6      1 /* SPI_ENABLE */
#define SPCR_BIT5      0 /* DATA_ORDER - 1:LSB 1st, 0:MSB 1st */
#define SPCR_BIT4      1 /* MASTER - 1 / SLAVE - 0 */
#define SPCR_BIT3      0 /* CLOCK_POLARITY */
#define SPCR_BIT2      0 /* CLOCK_PHASE */
#define SPCR_BIT10     3 /* CLOCK_RATE */
#endif

#define SPCR_SETUP  (0 | \
(SPCR_BIT10) | \
(SPCR_BIT2 << 2) | \
(SPCR_BIT3 << 3) | \
(SPCR_BIT4 << 4) | \
(SPCR_BIT5 << 5) | \
(SPCR_BIT6 << 6) | \
(SPCR_BIT7 << 7))

#if (!SPI_CONFIGURED)
#define SPSR_BIT7      0 /* SPI_IT_FLAG */
#define SPSR_BIT6      0 /* WRITE_COLLISION_FLAG */
#define SPSR_BIT0      0 /* DOUBLE_SPEED */
#else
#define SPSR_BIT7      0 /* SPI_IT_FLAG */
#define SPSR_BIT6      0 /* WRITE_COLLISION_FLAG */
#define SPSR_BIT0      0 /* DOUBLE_SPEED */
#endif

#define SPSR_SETUP  (0 | \
SPSR_BIT0 | \
(SPSR_BIT6 << 6) | \
(SPSR_BIT7 << 7))

/*************************************/

#if (!USART_CONFIGURED)
#define UCSRB_SETUP  0
#define UCSRC_SETUP  0

#else
#define UCSRB_BIT4   1 /* RX_ENABLE */
#define UCSRB_BIT3   1 /* TX_ENABLE */
#define UCSRB_BIT2   0 /* UCSZ2 - CHAR_SIZE */
#define UCSRB_BIT1   0 /* RXB8 */
#define UCSRB_BIT0   0 /* TXB8 */
#define UCSRB_SETUP  (0 | \
UCSRB_BIT0 | \
(UCSRB_BIT1 << 1) |\
(UCSRB_BIT2 << 2) |\
(UCSRB_BIT3 << 3) |\
(UCSRB_BIT4 << 4))

#define UCSRC_BIT7   0 /* URSEL */
#define UCSRC_BIT6   0 /* UMSEL */
#define UCSRC_BIT54  0 /* UPM */
#define UCSRC_BIT3   0 /* USBS */
#define UCSRC_BIT21  3 /* UCSZ1:0 */
#define UCSRC_BIT0   0 /* UCPOL */
#define UCSRC_SETUP  (0 | \
UCSRC_BIT0 | \
(UCSRC_BIT21 << 1) |\
(UCSRC_BIT3 << 3)  |\
(UCSRC_BIT54 << 4) |\
(UCSRC_BIT6 << 6)  |\
(UCSRC_BIT7 << 7))

#endif

/*************************************/



#endif /* PROJECTCONFIG_H_ */
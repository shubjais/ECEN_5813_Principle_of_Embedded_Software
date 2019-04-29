/*
 * adc.c
 *
 *  Created on: Apr 21, 2019
 *  Author: Shubham Jaiswal, Ayush Dhoot
 */

#include "adc.h"

void adc_init()
{
	/*Enable ADC Clock gates*/
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
	ADC0->CFG1=0;
	ADC0->SC3=0;
	ADC0->SC1[0] |= ADC_SC1_ADCH_MASK;  //Disable ADC first.

	//  Bus/2 clock selected, 16-bit single-ended, and divide factor is input_clock/8
	ADC0->CFG1 |= ADC_CFG1_ADICLK(1) | ADC_CFG1_MODE_MASK | ADC_CFG1_ADIV_MASK;
	ADC0->SC1[0] &= ~(ADC_SC1_AIEN_MASK) & ~(ADC_SC1_DIFF_MASK);							// Interrupts disable,
	ADC0->SC2 |=  ADC_SC2_DMAEN_MASK;	 // Enable ADC DMA request

	// Continuous Conversion, Hardware averaging, 32 samples averaged.
	ADC0->SC3 |= ADC_SC3_ADCO_MASK | ADC_SC3_AVGE_MASK | ADC_SC3_AVGS_MASK;
}

/*
 * Enables ADC channel O in single ended mode.
 */
void adc_enable()
{
	ADC0->SC1[0] &= ~ADC_SC1_ADCH_MASK;
}

/*
 * Returns data from ADC result data register
 */
uint16_t adc_read()
{
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK)); //Wait till conversion completes
	return ADC0->R[0];
}

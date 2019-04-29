/*
 * adc.h
 *
 *  Created on: Apr 21, 2019
 *      Author: Shubham Jaiswal
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "MKL25Z4.h"

void adc_init();
void adc_enable();
uint16_t adc_read();

#endif /* ADC_H_ */

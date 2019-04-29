/*
 * dma.h
 *
 *  Created on: Apr 21, 2019
 *      Author: Shubham Jaiswal, Ayush Dhoot
 */

#ifndef DMA_H_
#define DMA_H_

/***************************************************Include Header Files******************************************************/
#include "MKL25Z4.h"
#include <stdint.h>
#include "main.h"
#include "adc.h"
/*****************************************************************************************************************************/
/***************************************************Global Variable declaration**********************************************/

volatile uint8_t dma_irq_exit = 0; //Flag to check DMA ISR entry and exit.
uint16_t d_buff[128];					// Array to represent double Buffer.
uint16_t d_buff1 = 0;					//Array index to represent 1st part of double Buffer
uint16_t d_buff2 = 64;				//Array index to represent 2nd part of double Buffer
/*****************************************************************************************************************************/
/*******************************************Function declarations/prototypes**************************************************/
void dma_init(void);
void DMA0_IRQHandler(void);
/*****************************************************************************************************************************/
#endif /* DMA_H_ */

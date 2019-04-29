/*
 * dma.c
 *
 *  Created on: Apr 19, 2019
 *  Author: Ayush Dhoot, Shubham Jaiswal
 *
 */


/*
 * Reference: https://community.nxp.com/docs/DOC-102951
 * DMA example
 */


#include "dma.h"

/*
 * Function to Initialize DMA peripheral and DMAMUX to source channel 0 of ADC to channel 0 of DMA.
 */
void dma_init(void)
{
	SIM->SCGC6 |= SIM_SCGC6_DMAMUX_MASK;					// Clock to DMA mux
	SIM->SCGC7 |= SIM_SCGC7_DMA_MASK;					// Clock to DMA module

	DMAMUX0->CHCFG[0] = 0x00;								// Disable DMAMUX

	DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;				// Clearing previous errors
	DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;				// Ensuring the clear
	DMA0->DMA[0].SAR = 0x4003B010;								// Source Address
	DMA0->DMA[0].DSR_BCR |=DMA_DSR_BCR_BCR(128);				// 128 - 64(Number of elements in a part of buffer) * 2(BCR decrement as 16-bit) = 0
	DMA0->DMA[0].DCR &= ~(DMA_DCR_SSIZE_MASK | DMA_DCR_DSIZE_MASK); //clear source size and destination size fields

	// Configure DMA source, destination size, enable DMA interrupt, Enable peripheral request, Increment Destination address
	DMA0->DMA[0].DCR |= DMA_DCR_SSIZE(2) | DMA_DCR_DSIZE(2) | DMA_DCR_DINC_MASK | DMA_DCR_DMOD(0) | DMA_DCR_ERQ_MASK  | DMA_DCR_EADREQ_MASK | DMA_DCR_CS_MASK  | DMA_DCR_EINT_MASK;
	DMA0->DMA[0].DAR = (uint32_t)&d_buff[d_buff1];								// Destination address

	DMAMUX0->CHCFG[0] |= DMAMUX_CHCFG_SOURCE(40) | DMAMUX_CHCFG_ENBL_MASK;			// Select source as ADC0, Enable DMAMUX

	__enable_irq();										// Enable interrupts
	NVIC_EnableIRQ(DMA0_IRQn);
}

/*
 * Handles DMA0 interrupt and reset the BCR data fields with 128.
 */

void DMA0_IRQHandler(void)
{
	/*GPIO set*/
	GPIOD->PSOR |= (1 << 1);

	/* Clear DMA Interrupt and error bits.*/
	DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;	// Clear Done Flag
	DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;

	if(buff_change_flag==1)
		{
			DMA0->DMA[0].DAR = (uint32_t)&d_buff[d_buff1];		//Toggle Buffer
			buff_change_flag=0;
		}
	else
		{
			DMA0->DMA[0].DAR = (uint32_t)&d_buff[d_buff2];		//Toggle Buffer
			buff_change_flag=1;
		}

	DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_BCR(128);		// Set byte count register to start interrupt again.

	/*GPIO clear*/
	GPIOD->PCOR |= (1 << 1);

	dma_irq_exit=1;    //Set IRQ exit flag
}

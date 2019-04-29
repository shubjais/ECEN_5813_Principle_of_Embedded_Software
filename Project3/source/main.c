/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

#include "main.h"


int buff_change_flag = 0;

/*!
 * @brief Main function
 */
int main(void)
{
    //char ch;

    /* Init board hardware.*/
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    //Initialize peripherals
    init_LED();
    adc_init();
    dma_init();

    PRINTF("hello world.\r\n");

    //Enable ADC
    adc_enable();

    while (1)
    {
    	if (dma_irq_exit == 1)  //Check if Buffer was filled be DMA ISR
    	{
    		peak_calculation();
    		dma_irq_exit = 0;			// Clear the flag
    	}
    }
}

/*
 * Peak level calculation
 */
void peak_calculation(void)
{
	uint16_t index;
	if (buff_change_flag == 1)    // Check which buffer did DMA release
	{
		index = d_buff1;
	}
	else
	{
		index = d_buff2;
	}
	new_peak = d_buff[index];

	for(uint16_t i = index; i < (index + 64); i++)  //Calculate the peak in the just received buffer
	{

		if(new_peak < d_buff[i])
		{
			new_peak = d_buff[i];
		}
	}

	if(prev_peak < new_peak)			//Compare new potential peak with the prev established peak
	{
	    PRINTF("no decay\r\n");
	    peak = new_peak;
	    prev_peak = new_peak;				//Replace new peak with previous peak
	}
	else
	{
		peak = alpha * peak;				//Decay the peak if potential peak is smaller
	}

 	PRINTF("\tADC Peak value: %d In Hex: %x\r\n", peak, peak);
 	dbfs_calc(peak);
	PRINTF("*********************************************************\r\n");
}

/*
valueDBFS = 20*log10(value/65536)
*/

void dbfs_calc(uint16_t peak)
{
	float peak_dbfs,peak_log;
	for(int i = 0; i < 40; i++)
	{
		if(peak <= log_lookup_table[i].max_val_range && peak >= log_lookup_table[i].min_val_range)  // Look for peak value in log_lookup_table
		{
			peak_log = log_lookup_table[i].log_value;
			break;
		}
	}
	peak_dbfs = 20*peak_log;						//Calculate DBFS value
	PRINTF("\tIn DBFS: %.2f \r\n ", peak_dbfs);
}

void init_LED(void)
{
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;       // Enable Port D clock
	PORTD->PCR[1] |= PORT_PCR_MUX(1);		//Set function as GPIO
	GPIOD->PDDR |= (1 << 1);				//Set GPIO as output
}

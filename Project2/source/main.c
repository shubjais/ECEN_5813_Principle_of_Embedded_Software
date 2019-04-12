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
/*========================================================================
** main.c
** ECEN5813
** Submitted By: Shubham Jaiswal, Ayush Dhoot
**========================================================================*/

#include "main.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/


char report[256]={0};

/*
Reference: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
Calculates the fibonacci number.
*/


int fib(int16_t n)
{
  int a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}

/*Prints the application report for PART5.
Skips if number of characters received is 0.
*/
void print_report(void)
{
	for(int i=0; i<256; i++)
	{
		if( report[i] > 0)
		{
			my_printf_irq("\n\r");
			my_printf_irq("%c => %d",i, report[i]);
			my_printf_irq("\n\r");
		}
	}
}

void init_LED(void)
{
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	PORTB->PCR[18] |= PORT_PCR_MUX(1);
	GPIOB->PDDR |= (1 << 18);
}

void toggle_LED(void)
{
	 GPIOB->PTOR |= (1 << 18);
	 for(int i=0 ; i< 100000; i++)
	 {

	 }
}
/*!s
 * @brief Main function
 */

int main(void)
{
    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    uart_initialize();		// Initialize UART clock, pins and configure baud rate.
    init_LED();              //initialize led clock, pins and direction
    //BOARD_InitDebugConsole();
    Buff_Ptr = init((int)CBUF_LENGTH);
    my_printf_irq("Hello! UART and Circular buffer have been initialized.");
    my_printf_irq("\n\rPlease Input some Characters:");

    while (1)
    {
			if(tx_flag == 1)
			{
				__disable_irq();
				tx_flag = 0;
				__enable_irq();
				while(num != 0)
				{
					Buff_data = remove_element(Buff_Ptr);
					//report[Buff_data]++;
					if(num == 0)
					{
						my_printf_irq("\n\rFibonnaci Number for number %d is %d",char_count, fib(char_count));
						print_report();
					}
				}
			}
				toggle_LED(); //toggles the LED.
    }
}

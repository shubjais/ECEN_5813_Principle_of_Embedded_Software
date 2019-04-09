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


#include "main.h"

//#include "fsl_debug_console.h"

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
https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
*/

int fib(int n)
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

void print_report(void)
{


	for(int i=0; i<256; i++)
	{
		if( report[i] > 0)
		{

			my_printf("\n\r");
			my_printf("%c => %d", i, report[i]);
			my_printf("\n\r");
		}
	}
	my_printf("\n\rFibonnaci Number for number %d is %d", num, fib(num));
	rep_flag=0;
}

/*!s
 * @brief Main function
 */

int main(void)
{
    //char ch;

    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    uart_initialize();
    //BOARD_InitDebugConsole();
    Buff_Ptr = init((int)LENGTH);
    //PRINTF("hello world.\r\n");
    int len = LENGTH;
    my_printf("Hello!");


    //int n=9;

//    my_printf("Fibonnaci Number for number %d is %d", n, fib(n));

    //Buff_Ptr = buffer_resize(Buff_Ptr, (LENGTH+6));

    //char *startadd = Buff_Ptr->Buffer;
    while (1)
    {


/*
    	if(num>2)
    	{
    	for(int i=0; i<num; i++)
    	{
    		my_printf("Buffer element %d : %c", i, *startadd);
    		startadd++;
    	}

    }
*/



   // if(entries(Buff_Ptr) == len)
    if(Buff_Ptr->Buffer_full)
    {
    	len=len+6;
    	Buff_Ptr = buffer_resize(Buff_Ptr, len);
    	Buff_Ptr->Buffer_full = false;
    }

	if (rep_flag == 1)
	{
			print_report();
			//break;
	}

    }
}

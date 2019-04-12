/*
 * uart.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Shubham Jaiswal, Ayush Dhoot
 */

#include "uart.h"

uint16_t number = 0;
uint16_t divisor_check = 0;
uint16_t divisor = 0;
int8_t power = 0;
uint8_t send_count = 0;
volatile int8_t rx_data = 0;

/*
Initialize UART (clock, BAUD rate, interrupts, registers)
*/

void uart_initialize()
{
	uint16_t SBR;
	uint8_t temp;
	//Enable PORTA Clock gate
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	//Enable UART Clock gate
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM->SOPT2 |= 0x4000000;
	// Enable the pins of UART output
	PORTA->PCR[1] = (PORTA->PCR[1] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(2); // Select the function of PTC3 to be UART1RX
	PORTA->PCR[2] = (PORTA->PCR[2] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(2); // Select the function of PTC4 to be UART1TX

	//Disable Transmitter and Receiver
	UART0->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
	UART0->C1 &= 0x0;

	UART0->BDH &= ~UART0_BDH_SBNS(1);

	/*Baud Config*/
	SBR= (uint16_t)((UART0_CLOCK_FREQ)/(16 * UART0_BAUD_RATE));

	// Strip off the current value of the UARTx_BDH except for the SBR field
	temp = UART0->BDH & ~(UART0_BDH_SBR_MASK);

	// Set Baud Rate Registers
	UART0->BDH = temp | UART0_BDH_SBR(((SBR & 0x1F00) >> 8));
	UART0->BDL = (uint8_t)(SBR & UART0_BDL_SBR_MASK);

	/*Enable Transmitter, Receiver and Receiver interrupt*/
	UART0->C2 |= (UART0_C2_TE_MASK) | (UART0_C2_RE_MASK) | (UART0_C2_RIE_MASK);

	/*Enable IRQ*/
	__enable_irq();

	NVIC_EnableIRQ(UART0_IRQn);
}

/*
Blocking mode (Polling) UART write
*/
void uart_write(int8_t data)
{
	while(!(UART0->S1 & UART0_S1_TDRE_MASK)); //Wait for transmit buffer to get empty
	UART0->D = data;
	while(!(UART0->S1 & UART0_S1_TC_MASK)); //Wait till transmission is complete
}

/*
Non-Blocking mode (IRQ) UART write
*/
void uart_write_irq(int8_t data)
{
	UART0->C2|=(UART0_C2_TIE_MASK); //Wait for transmit buffer to get empty
	UART0->D = data;
	while(!(UART0->S1 & UART0_S1_TC_MASK)); //Wait till transmission is complete
}

/*
Non-Blocking mode (IRQ) UART read
*/
int8_t uart_read()
{
	int8_t data;
	while((UART0->S1 & UART0_S1_RDRF_MASK) == 0); //Wait for Receive data Register to get full
	data = UART0->D;
	insert(Buff_Ptr,data); // Insert data in Circular Buffer
	return data;
}

/*
Interrupt handler for sending or receiving characters
*/
void UART0_IRQHandler()
{
	__disable_irq();
	if(UART0->S1 & UART0_S1_RDRF_MASK)
	{
		rx_data=UART0->D;
		insert(Buff_Ptr,rx_data);
		report[rx_data]++;
		char_count++;
	}

	 if (UART0->S1 & UART0_S1_TDRE_MASK)
	 {
		 tx_flag = 1;						//Scheduler Flag
		 UART0->C2 &=~ UART0_C2_TIE_MASK;		//Disabling Tx interrupts
	 }
	 __enable_irq();

}


/*
 * Creating a new printf function which uses non-blocking UART
 *
 * Reference: http://www.firmcodes.com/write-printf-function-c/
*/

void my_printf_irq(char	*format,...)
{
	char *traverse;
	unsigned int i;
	char *s;

	//Module 1: Initializing Myprintf's arguments
	va_list arg;
	va_start(arg, format);

	for(traverse = format; *traverse != '\0'; traverse++)
	{
		if( *traverse != '%' )
		{
			uart_write_irq(*traverse);
		}

		else
		{
			traverse++;
			//Module 2: Fetching and executing arguments
			switch(*traverse)
			{
				case 'c' : i = va_arg(arg,int);		//Fetch char argument
							uart_write_irq(i);
							break;

				case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
							if(i<0)
							{
								i = -i;
								uart_write_irq('-');
							}
							//puts(convert(i,10));
							s = convert(i,10);
							while(*s != '\0')
							{
								uart_write_irq(*s);
								s++;
							}
							break;
			}
		}
	}

	//Module 3: Closing argument list to necessary clean-up
	va_end(arg);
}

char *convert(unsigned int num, int base)
{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}while(num != 0);

	return(ptr);
}

/*
 * uart.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Shubham Jaiswal, Ayush Dhoot
 */

#ifndef UART_H_
#define UART_H_

#include "main.h"
#include "MKL25Z4.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include "ring.h"

#define UART_CLOCK_FREQ 48000000
#define BAUD_RATE (115200)

void uart_initialize();
void uart_write(int8_t);
int8_t uart_read();
void my_printf(char *,...);
char *convert(unsigned int, int);
//void report(int8_t);

extern uint16_t number;
extern uint16_t divisor_check;
extern uint16_t divisor;
extern int8_t power;
extern uint8_t send_count;
//int8_t resize_flag;

extern volatile int8_t rx_data;
//volatile int8_t x;
//uint8_t p_flag;
//uint8_t s_flag;
//volatile int8_t data;


#endif /* UART_H_ */

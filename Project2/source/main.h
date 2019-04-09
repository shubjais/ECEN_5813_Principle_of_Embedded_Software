/*
 * main.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Shubham Jaiswal, Ayush Dhoot
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "fsl_device_registers.h"
//#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "ring.h"
#include "uart.h"

#define LENGTH (26)

int fib(int n);
ring_t *Buff_Ptr;

volatile uint16_t count;
volatile uint16_t total_char_count;
uint8_t rep_flag = 0;
uint8_t rx_flag = 0;

extern char report[256];

void print_report(void);

#endif /* MAIN_H_ */

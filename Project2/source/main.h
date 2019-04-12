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

#define CBUF_LENGTH (26)

int fib(int16_t n);
ring_t *Buff_Ptr;

volatile uint16_t count;
volatile uint16_t total_char_count;
uint8_t rep_flag = 0;
//uint8_t rx_flag = 0;
uint8_t tx_flag = 0;
uint16_t char_count = 0;
int8_t Buff_data;
extern char report[256];

void print_report(void);
void init_LED(void);
void toggle_LED(void);

#endif /* MAIN_H_ */

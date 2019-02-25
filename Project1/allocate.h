/*****************************************************************************
* Copyright (C) 2019 by Shubham Jaiswal and Ayush Dhoot
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Shubham Jaiswal, Ayush Dhoot and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/**
* @file allocate.h
* @brief An abstraction for memory read and write operations
*
* This header file provides an abstraction of allocating the memory.
*
* @author Shubham Jaiswal, Ayush Dhoot
* @date February 21, 2019
* @version 1.0
*
*/

#ifndef ALLOCATE_H
#define ALLOCATE_H allocate.h


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
uint32_t *first_ptr;
uint32_t *last_ptr;
int mem_allocate;


void allocate_mem(void);


#endif
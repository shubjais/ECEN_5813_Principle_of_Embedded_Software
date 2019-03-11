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
* @file free.h
* @brief An abstraction for memory read and write operations
*
* This header file provides an abstraction of freeing the allocated memory.
*
* @author Shubham Jaiswal, Ayush Dhoot
* @date February 21, 2019
* @version 1.0
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "allocate.h"

#ifndef FREE_H 
#define FREE_H free.h

int free_mem(void);

#endif

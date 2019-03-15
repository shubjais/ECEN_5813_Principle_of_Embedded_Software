/*****************************************************************************
* Copyright (C) 2019 by Ayush Dhoot and Shubham Jaiswal
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Ayush Dhoot, Shubham Jaiswal and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/**
* @file displaymem.h
* @brief Function declarations
* @author Ayush Dhoot and Shubham Jaiswal
* @date February 23, 2019
* @version 1.0
*
*/



#ifndef DISPLAYMEM_H
#define DISPLAYMEM_H displaymem.h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "allocate.h"
#include "platformselect.h"

int display_mem(void);

#endif

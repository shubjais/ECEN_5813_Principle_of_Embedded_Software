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
* @file main.h
* @brief Function declarations and global variables declaration
* @author Ayush Dhoot and Shubham Jaiswal
* @date February 22, 2019
* @version 1.0
*
*/

#ifndef MAIN_H
#define MAIN_H main.h

#include <stdio.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "help.h"
#include "exit.h"
#include "allocate.h"
#include "free.h"
#include "displaymem.h"
#include "writemem.h"
#include "invert.h"
#include "writepattern.h"
#include "verifypattern.h"
#include "platformselect.h"

typedef struct
{
char *ip;
int (*my_func)();

}table;
 

char input[15];


#endif

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
* @file verifypattern.h
* @brief Function declarations
* @author Ayush Dhoot and Shubham Jaiswal
* @date February 27, 2019
* @version 1.0
*
*/

#ifndef VERIFYPATTERN_H
#define VERIFYPATTERN_H VERIFYPATTERN.H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "allocate.h"
#include "writepattern.h"

int verify_pattern(void);

#define MODULUS    2147483647 // DON'T CHANGE THIS VALUE                  */
#define MULTIPLIER 48271      // DON'T CHANGE THIS VALUE   



#endif 
/*
 * platformselect.h
 *
 *  Created on: Mar 14, 2019
 *      Author: aayus
 */

#ifndef PLATFORMSELECT_H_
#define PLATFORMSELECT_H_

//#define KL25Z
#define LINUX

#ifdef KL25Z
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#endif

#ifdef LINUX
#define PRINTF printf
#define SCANF scanf
#endif


#endif /* PLATFORMSELECT_H_ */

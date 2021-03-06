/*
 * main.h
 *
 *  Created on: Apr 21, 2019
 *      Author: Shubham Jaiswal, Ayush Dhoot
 */

#ifndef MAIN_H_
#define MAIN_H_
/***********************************************************************************************************/
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#include "math.h"
/***********************************************************************************************************/
/***********************************************************************************************************/
#include "adc.h"
#include "dma.h"
/***********************************************************************************************************/
/***********************************************************************************************************/
#define alpha (0.7)      //Decay factor
/***********************************************************************************************************/
/***********************************************************************************************************/
extern int buff_change_flag;
uint16_t peak = 0;
uint16_t new_peak = 0;
uint16_t prev_peak = 0;

typedef struct
{
	float min_val_range;
	float max_val_range;
	float log_value;
}log_lookup;

log_lookup log_lookup_table[] = {{0,1638.4,-1.60}, {1638.4,3276.8,-1.30}, {3276.8,4915.2,-1.12}, {4915.2,6553.6,-0.99}, {6553.6,8192, -0.90},
								{8192,9830.4,-0.82}, {9830.4,11468.8,-0.75}, {11468.8,13107.2,-0.69}, {13107.2,14745.6,-0.64}, {14745.6,16384,-0.60},
								{16384,18022.4,-0.56}, {18022.4,19660.8,-0.52}, {19660.8,21299.2,-0.48}, {21299.2,22937.6,-0.45}, {22937.6,24576,-0.42},
								{24576,26214.4,-0.39}, {26214.4,27852.8,-0.37}, {27852.8,29491.2,-0.34}, {29491.2,31129.6, -0.32}, {31129.6,32768,-0.30},
								{32768,34406.4,-0.27}, {34406.4 ,36044.8 ,-0.25}, {36044.8, 37683.2 ,-0.24}, {37683.2, 39321.6,-0.22}, {39321.6, 40960.0, -0.20},
								{40960.0,42598.4,-0.18}, {42598.4, 44236.8,-0.17}, {44236.8,45875.2 ,-0.15}, {45875.2, 47513.6,-0.13}, {47513.6, 49152.0,-0.12},
								{49152.0 ,50790.4 ,-0.11}, {50790.4 ,52428.8 ,-0.09}, {52428.8, 54067.2,-0.08}, {54067.2,55705.6,-0.07}, {55705.6, 57344.0 ,-0.05},
								{57344.0 ,58982.4 ,-0.04}, {58982.4 ,60620.8 ,-0.03}, {60620.8 ,62259.2 ,-0.02}, {62259.2, 63897.6, -0.01}, {63897.6 ,65536.0,0}
};
/***********************************************************************************************************/
/***********************************************************************************************************/
void peak_calculation(void);
void dbfs_calc(uint16_t peak1);
void init_LED(void);
/***********************************************************************************************************/
#endif /* MAIN_H_ */

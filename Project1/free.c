/**
* @brief Free the allocated memory
* *
* @author Ayush Dhoot and Shubham Jaiswal
*/


#include "free.h"

void free_mem()
{
	free(ptr);
	for(int j = 0; j < 4; j++)
	{
		printf("%x\n",*ptr);
	}
	printf("Memory Block freed.\n");
}

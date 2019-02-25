/**
* @brief Free the allocated memory
* *
* @author Ayush Dhoot and Shubham Jaiswal
*/


#include "free.h"

void free_mem()
{
	free(first_ptr);
	
	printf("Memory Block freed.\n");
}

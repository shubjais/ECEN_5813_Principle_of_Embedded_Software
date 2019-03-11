/**
* @brief Free the allocated memory
* *
* @author Ayush Dhoot and Shubham Jaiswal
*/


#include "free.h"


int free_mem()
{
	if(first_ptr == NULL)
	{
		printf("No memory block allocated or Block already freed.\n");
		return -1;
	}

	free(first_ptr);

	if(first_ptr != NULL)
	{
		printf("Memory Block freed.\n");
		first_ptr = NULL;
	}
	return 0;
}

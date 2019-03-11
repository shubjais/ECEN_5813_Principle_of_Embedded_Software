/**
* @brief Free the allocated memory
* *
* @author Ayush Dhoot and Shubham Jaiswal
*/


#include "free.h"


int free_mem()
{
	if(first_ptr == NULL) // Check if any memory block is allocated or not.
	{
		printf("No memory block allocated or Block already freed.\n");
		return -1;
	}

	free(first_ptr); // free the allocated block of memory.

	if(first_ptr != NULL) // After freeing the allocated block, remove the pointer to the allocated block.
	{
		printf("Memory Block freed.\n");
		first_ptr = NULL;
	}
	return 0;
}

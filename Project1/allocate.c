/**
* @brief Allocate memory in multiples of 32 bit words
*
* @author Ayush Dhoot and Shubham Jaiswal
*/

#include "allocate.h"

void allocate_mem()
{
	printf("Enter the number of 32 bit words to be allocated: ");
	scanf("%d",&mem_allocate);
	printf("\n");
	ptr = (uint32_t *)malloc(mem_allocate * 4);
	last_ptr = ptr + (mem_allocate - 1);

	if(ptr == NULL)
	{
		printf("Memory cannot be allocated.\n");
		exit(0);
	}

	printf("Starting address of allocated memory: %p", ptr);
	printf("\n");

}
/**
* @brief Allocate memory (in multiples of 32 bit words)
*
* @author Ayush Dhoot and Shubham Jaiswal
*/

#include "allocate.h"

int allocate_mem()
{
	while(1)
	{
		printf("Enter the number of 32 bit words to be allocated: ");
		scanf("%d",&mem_allocate);
		printf("\n");
		if(mem_allocate <= 0) //Checking whether the entered input is valid or not.
		{
			printf("Please enter a valid input greater than 0.\n");
		}
		else
		{
			break;
		}
	}
	first_ptr = (uint32_t *)malloc(mem_allocate * 4);		//starting address of the allocated memory
	last_ptr = first_ptr + (mem_allocate - 1);				//end address of allocated memory

	if(first_ptr == NULL)									//check if the allocated memory is null
	{
		printf("Memory cannot be allocated.\n");
		return (-1);
	}

	printf("Starting address of first block of allocated memory: %p", first_ptr);
	printf("\n");
	return 0;
}

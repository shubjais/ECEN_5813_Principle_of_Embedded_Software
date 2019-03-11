/**
* @brief Invert the memory contents using a bitwise NOT operation and calculate the time taken to perform the operation
*
* @author Ayush Dhoot and Shubham Jaiswal
*/

#include "invert.h"
#include <time.h>

int invert_mem()
{
	uint32_t *inv_addr;
	uint32_t *i, *j;
	int choice, offset, valid_n = 0, words_available = 0, input_no_words = 0;

	if(first_ptr == NULL)  // Check if any memory block is allocated or not.
	{
		printf("No memory block is allocated. Please allocate a memory block first.\n");
		return -1;  // Change it with return later on.
	}
	else
	{
		printf("Allocated memory addresses on which data can be inverted:\n"); // print the address of allocated blocks
		for(i = first_ptr; i <= last_ptr; i++)
		{
			printf("\n%p",i);
		}

		printf("\n\nPlease select one of following ways to specify the address:"
				"\n1.Type the address of which you wish to invert the data"
				"\n2.Give an offset from %p"
				"\n3.Exit command.\n", first_ptr);
		while(1)  // Ask user the address of the block at which he/she wishes to invert the data.
		{
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
				printf("Enter the address of memory block of which you wish to see the data\n");
				scanf("%p", &inv_addr);
				break;

				case 2:
				printf("Enter the offset from memory address %p:", first_ptr);
				scanf("%d", &offset);
				inv_addr = first_ptr + offset;
				break;

				case 3:
				return 0;

				default:
				printf("Not a valid input.Please try again with a valid Input or enter 3 to input another command:\n");
			}

			if(choice == 1 || choice == 2)
			{
				break;
			}
		}

		//Ask user the number of blocks at which he/she wishes to invert the data.
		printf("Enter the no of word blocks data you wish to invert\n");
		scanf("%d", &input_no_words);

		//Check if the address provided by the user is among the allocated memory addresses.
		for(i = first_ptr;i <= last_ptr; i++)
		{		
			if(i == inv_addr)		
			{
				for (j = inv_addr; j <= last_ptr; j++)
				{
					words_available++;
				}
				if(input_no_words <= words_available) // check if the number of blocks demanded by user fall within the number of allocated blocks.
				{
					clock_t start = clock();  //start timer
					for(; input_no_words > 0 ; input_no_words--) // Invert data at the requested memory blocks.
					{
						printf("Data before inversion at address %p is %x\n", i, *i);
						*i = ~(*i);
						printf("Data after inversion at address %p is %x\n", i, *i);
						i++;
					}
					clock_t end = clock();  //end timer
					printf("\nTime taken to invert the bits at specified memory address(es):%f seconds",(double)(end - start) / CLOCKS_PER_SEC);
					printf("\n");
				}
				else
				{
					printf("Asked number of blocks not avaible from the desired address.\n");
					return -1;
				}
				break;
			} 
			else
			{
			 	valid_n++;					
			}
		}

		if(valid_n == mem_allocate)					//Condition to check whether entered address is valid or not
   		{
			printf("\nThe address entered is not a valid address");
			printf("\n");
			return -1;
		}
		
	}
	return 0;
}
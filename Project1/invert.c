/**
* @brief Invert the memory contents using a bitwise NOT operation 
*
* @author Ayush Dhoot and Shubham Jaiswal
*/

#include "invert.h"
#include <time.h>

void invert_mem()
{
	uint32_t *inv_addr;
	uint32_t *i, *j;
	int choice, offset, k = 0, words_available = 0, input_no_words = 0;

	if(first_ptr == NULL)
	{
		printf("No memory block is allocated. Please allocate a memory block first.\n");
		exit(0);  // Change it with return later on.
	}
	else
	{
		printf("Allocated memory addresses on which data can be inverted:\n");
		for(i = first_ptr; i <= last_ptr; i++)
		{
			printf("\n%p",i);
		}
		printf("\n\nPlease select one of following ways to specify the address:"
				"\n1.Type the address of which you wish to invert the data"
				"\n2.Give an offset from %p\n", first_ptr);
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
			default:
			printf("Not a valid input");
		}

		printf("Enter the no of word blocks data you wish to invert\n");
		scanf("%d", &input_no_words);

		for(i = first_ptr;i <= last_ptr; i++)
		{		
			if(i == inv_addr)		
			{
				for (j = inv_addr; j <= last_ptr; j++)
				{
					words_available++;
				}
				if(input_no_words <= words_available)
				{
					clock_t start = clock();
					for(; input_no_words > 0 ; input_no_words--)
					{
						printf("Data before inversion at address %p is %x\n", i, *i);
						*i = ~(*i);
						printf("Data after inversion at address %p is %x\n", i, *i);
						i++;
					}
					clock_t end = clock();
					printf("\nTime taken to invert the bits at specified memory address:%f seconds",(double)(end - start) / CLOCKS_PER_SEC);
					printf("\n");
				}
				else
				{
					printf("Asked number of blocks not avaible from the desired address.\n");
				}
			} 
			else
			{
			 	k++;					
			}
		}

		if(k == mem_allocate)					//Condition to check whether entered address is valid or not
   		{
			printf("\nThe address entered is not a valid address");
			printf("\n");
		}
		
	}
}
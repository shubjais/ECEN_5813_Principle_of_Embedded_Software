/**
* @brief Write data at user defined memory location
*
* @author Ayush Dhoot and Shubham Jaiswal
*/

#include "writemem.h"

int write_mem()
{
	uint32_t *write_addr;
	uint32_t *i, *j;
	int choice, offset, valid_n = 0, words_available = 0, input_no_words = 0;
	
	if(first_ptr == NULL) // Check if any memory block is allocated or not.
	{
		printf("No memory block is allocated. Please allocate a memory block first.\n");
		return -1; 
	}
	else 
	{
		printf("Allocated memory blocks on which data is to be written:\n"); // print the address of allocated blocks
		for(i = first_ptr; i <= last_ptr; i++)
		{
			printf("\n%p",i);
		}

		printf("\n\nPlease select one of following ways to specify the address:"
				"\n1.Type the address on which you wish to write the data"
				"\n2.Give an offset from %p"
				"\n3.Exit command.\n", first_ptr);
		while(1) // Ask user the address of the block at which he/she wishes to write the data.
		{
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
				printf("Enter the address at which you want to write\n");
				scanf("%p", &write_addr);
				break;

				case 2:
				printf("Enter the offset from memory address %p:", first_ptr);
				scanf("%d", &offset);
				write_addr = first_ptr + offset;
				break;

				case 3:
				return 0;
				
				default:
				printf("Not a valid input. Please try again with a valid Input or enter 3 to input another command:\n");
			}

			if(choice == 1 || choice == 2)
			{
				break;
			}
		}

		//Ask user the number of blocks at which he/she wishes to write the data.
		printf("Enter the no of word blocks data you wish to write\n");
		scanf("%d", &input_no_words);

		//Check if the address provided by the user is among the allocated memory addresses.
		for(i = first_ptr;i <= last_ptr; i++)
		{		
			if(i == write_addr)		
			{
				for (j = write_addr; j <= last_ptr; j++)
				{
					words_available++;
				}
				if(input_no_words <= words_available) // check if the number of blocks demanded by user fall within the number of allocated blocks.
				{
					for(; input_no_words > 0 ; input_no_words--) // Get data from user to be written.
					{
						printf("Enter the 32 bit value in hexadecimal form that you wish to write:");
						scanf("%x",i);				
						printf("\nValue written in the memory!!!\n");
						i++;
					}
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
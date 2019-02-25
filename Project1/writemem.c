/**
* @brief Write data at user defined memory location
*
* @author Ayush Dhoot and Shubham Jaiswal
*/

#include "writemem.h"

void write_mem()
{
	uint32_t *write_addr;
	uint32_t *i, *j;
	int choice, offset, valid_n = 0, words_available = 0, input_no_words = 0;
	
	if(first_ptr == NULL)
	{
		printf("No memory block is allocated. Please allocate a memory block first.\n");
		exit(0);  // Change it with return later on.
	}
	else 
	{
		printf("Allocated memory blocks on which data is to be written:\n");
		for(i = first_ptr; i <= last_ptr; i++)
		{
			printf("\n%p",i);
		}
		printf("\n\nPlease select one of following ways to specify the address:"
				"\n1.Type the address on which you wish to write the data"
				"\n2.Give an offset from %p\n", first_ptr);
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
			default:
			printf("Not a valid input");

		}

		printf("Enter the no of word blocks data you wish to write\n");
		scanf("%d", &input_no_words);

		for(i = first_ptr;i <= last_ptr; i++)
		{		
			if(i == write_addr)		
			{
				for (j = write_addr; j <= last_ptr; j++)
				{
					words_available++;
				}
				if(input_no_words <= words_available)
				{
					for(; input_no_words > 0 ; input_no_words--)
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
		}

	}
}
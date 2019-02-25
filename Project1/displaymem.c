/**
* @brief Display the contents of a user defined memory location
*
* @author Ayush Dhoot and Shubham Jaiswal
*/


#include "displaymem.h"

void display_mem()
{
	uint32_t *dis_addr;
	uint32_t *i, *j;
	int choice, offset, k = 0, words_available = 0, input_no_words = 0;
	

	if(ptr == NULL)
	{
		printf("No memory block is allocated. Please allocate a memory block first.\n");
		exit(0);  // Change it with return later on.
	}
	else 
	{
		printf("Allocated memory addresses on which data can be displayed:\n");
		for(i = ptr; i <= last_ptr; i++)
		{
			printf("\n%p",i);
		}
		printf("\n\nDo you wish to:\n(1)Type the address of which you wish to see the data\
		\n(2)Give an offset from %p\n", ptr);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the address of memory block of which you wish to see the data\n");
			scanf("%p", &dis_addr);
			break;
			case 2:
			printf("Enter the offset from memory address %p:", ptr);
			scanf("%d", &offset);
			dis_addr = ptr + offset;
			break;
			default:
			printf("Not a valid input");

		}
		printf("Enter the no of word blocks data you wish to see\n");
		scanf("%d", &input_no_words);

		for(i = ptr; i <= last_ptr; i++)
		{		
			if(i == dis_addr)		
			{
				for (j = dis_addr; j <= last_ptr; j++)
				{
					words_available++;
				}
				if(input_no_words <= words_available)
				{
					for(; input_no_words > 0 ; input_no_words--)
					{
						printf("Data at address %p is %x\n", dis_addr, *dis_addr);
						dis_addr++;
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

/**
* @brief Display the contents of a user defined memory location
*
* @author Ayush Dhoot and Shubham Jaiswal
*/


#include "displaymem.h"

int display_mem()
{
	uint32_t *dis_addr;
	uint32_t *i, *j;
	int choice, offset, valid_n = 0, words_available = 0, input_no_words = 0;
	

	if(first_ptr == NULL)														//check for uninitialized memory block
	{
		PRINTF("No memory block is allocated. Please allocate a memory block first.\n");
		return -1;  // Change it with return later on.
	}
	else 
	{
		//printf("Allocated memory addresses on which data can be displayed:\n"); // print the address of allocated blocks
		PRINTF("\n\rAllocated memory addresses on which data can be displayed:"); // print the address of allocated blocks
		for(i = first_ptr; i <= last_ptr; i++)							
		{
			//printf("\n%p",i);
			PRINTF("\n\r%p",i);
		}

		/*printf("\n\nPlease select one of following ways to specify the address:"
				"\n1.Type the address of which you wish to see the data"
				"\n2.Give an offset from %p"
				"\n3.Exit command.\n", first_ptr);*/
		PRINTF("\n\n\rPlease select one of following ways to specify the address:"
						"\n\r1.Type the address of which you wish to see the data"
						"\n\r2.Give an offset from %p"
						"\n\r3.Exit command.\n", first_ptr);

		while(1) // Ask user the address of the block at which he/she wishes to display the data.
		{
			//scanf("%d",&choice);
			SCANF("%d[^\n]",&choice);
			PRINTF("\n\r%d", choice);
			switch(choice)
			{
				case 1:
				//printf("Enter the address of memory block of which you wish to see the data\n");
				//scanf("%p", &dis_addr);
				PRINTF("\n\rEnter the address of memory block of which you wish to see the data\n");
				SCANF("%p", &dis_addr);
				PRINTF("\n\r%p", dis_addr);
				break;

				case 2:
				//printf("Enter the offset from memory address %p:", first_ptr);
				//scanf("%d", &offset);
				PRINTF("\n\rEnter the offset from memory address %p:", first_ptr);
				SCANF("%d", &offset);
				PRINTF("\t%d", offset);
				dis_addr = first_ptr + offset;
				break;

				case 3:
				return 0;

				default:
				PRINTF("\n\rNot a valid input.Please try again with a valid input or enter 3 to input another command:\n");

			}
			if(choice == 1 || choice == 2)
			{
				break;
			}
		}

		//Ask user the number of blocks at which he/she wishes to display the data.
		//printf("Enter the no of word blocks data you wish to see\n");
		//scanf("%d", &input_no_words);
		PRINTF("\n\rEnter the no of word blocks data you wish to see");
		SCANF("%d", &input_no_words);
		PRINTF("\t%d", input_no_words);

		//Check if the address provided by the user is among the allocated memory addresses.
		for(i = first_ptr; i <= last_ptr; i++)
		{		
			if(i == dis_addr)		
			{
				for (j = dis_addr; j <= last_ptr; j++)
				{
					words_available++;
				}
				if(input_no_words <= words_available) // check if the number of blocks demanded by user fall within the number of allocated blocks.
				{
					for(; input_no_words > 0 ; input_no_words--) //print data at the requested memory nlocks.
					{
						//printf("Data at address %p is %x\n", dis_addr, *dis_addr);
						PRINTF("\n\rData at address %p is %x\n", dis_addr, *dis_addr);
						dis_addr++;
					}
				}
				else
				{
					//printf("Asked number of blocks not avaible from the desired address.\n");
					PRINTF("\n\rAsked number of blocks not avaible from the desired address.\n");
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
			//printf("\nThe address entered is not a valid address");
			//printf("\n");
			PRINTF("\n\rThe address entered is not a valid address");
			PRINTF("\n\r");
			return -1;
		}
	}	
	return 0;
}
